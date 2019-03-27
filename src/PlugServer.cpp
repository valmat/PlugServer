/**
 *  PlugServer.cpp
 *
 *  Simple RocksDB server
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

#include "PlugServer.h"

using namespace PlugServer;

int main(int argc, char **argv)
{
    
    if (argc < 2) {
        std::cout << "Run as:" << std::endl << argv[0] << " <config.ini file name>" << std::endl;
        return 1;
    }
    std::cout << "PlugServer version is " << PLUGSERVER_VERSION << std::endl;


    /**
     *  
     *  Prevent server crash on signal SIGPIPE
     *  
     */    
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        return 1;
    }


    /**
     *  
     *  Init config
     *  
     */
    IniConfigs cfg(argv[1]);
    if(!cfg) {
        std::cerr<<"Error with open file "<< argv[1] << std::endl;
        return 1;
    }
    DefaultConfigs dfCfg;


    /**
     *  
     *  Set nofile soft limit
     *   
     *  This option sets the soft limit on the number of simultaneously opened files
     *  (including sockets, pipe, log files, etc).
     *  You can see your current soft limit by command `ulimit -Sn` and your hard limit by command `ulimit -Hn`
     *  The value of the soft of limit must not exceed the value of hard limit.
     *  If for some reason the server will take a lot of connections,
     *  the number of which exceeds nofile_limit, then part of the connections will not be processed.
     *  Increase nofile_limit can solve the problem.
     *  
     *  
     */
    auto nofile_limit = cfg.get("nofile_limit", dfCfg.nofile_limit);
    // if 0 then leave as default
    if(nofile_limit) {
        rlimit rlim;
        getrlimit(RLIMIT_NOFILE, &rlim);
        const rlimit i_rlimit {nofile_limit, rlim.rlim_max};
        if(-1 == setrlimit(RLIMIT_NOFILE, &i_rlimit)) {
            std::cerr << "You tried to set the nofile soft limit to " << nofile_limit << "." << std::endl;
            std::cerr << "Current  nofile soft limit value is " << rlim.rlim_cur << "." << std::endl;
            std::cerr << "Current  nofile hard limit value is " << rlim.rlim_max << "." << std::endl;
            
        }
    }
    

    /**
     *  
     *  Init extensions
     *  
     */
    Extend ext;


    /**
     *  
     *  Init logging http server
     *  
     */
    EvLogger logger(cfg.get("log_level", dfCfg.log_level), 
                    cfg.get("error_log", dfCfg.error_log));

    // Check if logger started
    if (!logger) {
        std::cerr<<"Can't open log file" << std::endl;
        return 1;
    }

    // 
    // Init libevent
    // 
    if (!event_init()) {
        std::cerr << "Failed to init libevent." << std::endl;
        return 1;
    }

    // 
    // Init event http server
    // 
    EvServer server(cfg.get("server_host", dfCfg.server_host), 
                    cfg.get("server_port", dfCfg.server_port));

    // Check if server started
    if (!server) {
        std::cerr << "Failed to init http server." << std::endl;
        return 1;
    }


    // 
    // Set http server options
    // 
    EvServerOptions serverOptions;
    //Set the value to use for the Content-Type header when none was provided. 
    serverOptions.content_type     = cfg.get("content_type", dfCfg.content_type);
    // Sets the what HTTP methods are supported in requests accepted by this server
    serverOptions.allowed_methods  = EVHTTP_REQ_POST | EVHTTP_REQ_GET;
    // Limitations for body size (limit in bytes. 0 - unlimited)    
    serverOptions.max_body_size    = cfg.get("max_body_size", dfCfg.max_body_size);
    // Limitations for headers size (limit in bytes. 0 - unlimited)    
    serverOptions.max_headers_size = cfg.get("max_headers_size", dfCfg.max_headers_size);
    server.setOptions(serverOptions);
    
    
    // Load extentions
    ext.load(server, cfg, dfCfg);

    // 
    // Start the event loop
    // 
    if (!server.dispatch()) {
        std::cerr << "Failed to run message loop." << std::endl;
        return 1;
    }

    return 0;
}
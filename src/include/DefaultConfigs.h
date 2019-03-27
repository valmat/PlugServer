/**
 *  DefaultConfigs
 *
 *  Default configurations for PlugServer
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

#pragma once

namespace PlugServer {


    struct DefaultConfigs
    {
        /**
         *  Configs HTTP 
         */

        // HTTP server host
        std::string server_host = "127.0.0.1";

        // HTTP server port
        unsigned short server_port = 5577;

        // HTTP server content_type
        // Set the value to use for the Content-Type header
        std::string content_type = "text/plain; charset=UTF-8";

        // Limitations for body size
        // limit in bytes. 0 - unlimited
        size_t max_body_size = 0;

        // Limitations for headers size
        // limit in bytes. 0 - unlimited
        size_t max_headers_size = 0;

        // Error level
        EvLogger::Level log_level = EvLogger::Level::none;


        // Error log file name
        std::string error_log = "/var/log/plugserver/error.log";

        // Set nofile soft limit
        // This option sets the soft limit on the number of simultaneously opened files
        // (including sockets, pipe, log files, etc).
        // You can see your current soft limit by command `ulimit -Sn` and your hard limit by command `ulimit -Hn`
        // The value of the soft of limit must not exceed the value of hard limit.
        // If for some reason the server will take a lot of connections, the number of which exceeds nofile_limit, then part of the connections will not be processed.
        // Increase nofile_limit can solve the problem.
        //
        // 0 - default system value (usually 1024)
        unsigned short nofile_limit = 0;

        /**
         *  Etc 
         */

        // Path to PlugServer extentions directory
        std::string extdir = "/usr/lib/PlugServer/plugins";

    };

}

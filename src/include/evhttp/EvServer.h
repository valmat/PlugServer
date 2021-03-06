/**
 *  EvServer.h
 *
 *  This is a simple wrapper around evhttp_* functions
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

#pragma once

// Forward declaration
struct evhttp;
struct event_base;
struct event;

namespace PlugServer {

    class EvServer
    {
    public:
        /**
         *  Constructor
         *  @param  addr       IP addres, wich server will listen
         *  @param  port       port, wich server will listen
         */
        EvServer(const std::string& addr, unsigned short port);

        ~EvServer();

        /**
         *  Set server options
         *  @param options EvServerOptions struct
         */
        void setOptions(const EvServerOptions &options) const;

        /**
         *  Start the event loop
         */
        bool dispatch();

        /**
         *  Cast to a bool 
         *  For check if server successfully created
         */
        operator bool () const
        {
            return _http;
        }

        /**
         *  Bind request listener
         *  @param  path       path to listen
         *  @param  req        listener
         */
        void bind(const char *path, std::unique_ptr<RequestSuperBase> &&pReq);

        /**
         *  Bind request listener
         */
        void bind(const char *path, RequestSuperBase *pReq)
        {
            bind(path, std::unique_ptr<RequestSuperBase>(pReq));
        }

    private:

        evhttp *_http = nullptr;
        
        // event_base - structure to hold information and state for a Libevent dispatch loop
        event_base *_base;

        // The container for storing a requests listeners
        std::forward_list< std::unique_ptr<RequestSuperBase> > _reqList;

        // event handler for SIGINT signal
        event *_sigint = nullptr;
        // event handler for SIGTERM signal
        event *_sigterm = nullptr;
    };

}

/**
 *  EvLogger.h
 *
 *  Class for logging evhttp
 *
 *  This class contains a static field.
 *  Unfortunately, due to the architecture of libevent these field can't be removed.
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

#pragma once

namespace PlugServer {

    class EvLogger
    {

    public: 
        // none | debug | msg |  warn | error | fatal 
        enum class Level : int {
            debug  = 0, // EVENT_LOG_DEBUG,
            msg    = 1, // EVENT_LOG_MSG,
            warn   = 2, // EVENT_LOG_WARN,
            error  = 3, // EVENT_LOG_ERR,
            fatal,
            none
        };

        EvLogger(const Level &log_level, const std::string &filename);

    	~EvLogger()
        {
            if(_file) _file.close();
        }

        /**
         *  Cast to a bool 
         *  For check if logger successfully created
         */
        operator bool () const
        {
            return (_logLevel == Level::none) || _file;
        }

        static void writeLog(const char * msg, Level severity = Level::warn)
        {
            writeLog(static_cast<int>(severity), msg);
        }

    private:
        static void writeLog(int severity, const char * msg);
        static void write(const std::string &severity, const char * msg);

        static std::ofstream _file;
        static Level _logLevel;
    };

}


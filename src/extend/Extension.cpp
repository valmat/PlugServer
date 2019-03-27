/**
 *
 *  Extension.cpp
 *  Base class for PlugServer extension
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

#include "PlugServer.h"

namespace PlugServer {

    void Extension::bind(std::string &&path, listener_ptr &&listener)
    {
        server.bind(path.data(), std::move(listener) );
    }

}
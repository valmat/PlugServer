/**
 *  smpl_plug.cpp
 *
 *  Simple example of PlugServer plugin
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/RequestPing
 */

#include <plugserver/api.h>
#include "RequestPing.h"

using namespace PlugServer;

/*
 * Create plugin
 * 
 * You can use one of the following forms of macro PLUGIN with one, two or three arguments:
 *
 * PLUGIN(Extension extension, const IniConfigs& cfg)
 * PLUGIN(Extension extension)
 *
 * The macro `PLUGIN` is defined in plugserver/api.h. 
 * Instead of using the macro, you can write
 * `extern "C" void plugin(...)` if you like
 *
 * @param extension  object of Extension
 * @param cfg        Reference to configuration settings
 */
PLUGIN(Extension extension, const vlm::IniConfigs& /*cfg*/)
{
    extension.bind("/ping", new RequestPing());
}
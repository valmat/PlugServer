#ifndef PLUGSERVER_API_H
#define PLUGSERVER_API_H

#include <plugserver/version.h>

// C++ headers
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#include <vector>
#include <unordered_map>
#include <forward_list>

// C headers
#include <string.h>

// Type traits
#include <plugserver/traits.h>

// Server wrapper
#include <plugserver/evhttp/EvResponse.h>
#include <plugserver/evhttp/PostData.h>
#include <plugserver/evhttp/EvRequest.h>
#include <plugserver/evhttp/EvServerOptions.h>
#include <plugserver/evhttp/EvLogger.h>

// Configs
#include <plugserver/iniparse/IniValue.h>
#include <plugserver/iniparse/IniConfigs.h>
#include <plugserver/iniparse/DefaultConfigs.h>

// Protocol
#include <plugserver/protocols/ProtocolOut.h>
#include <plugserver/protocols/ProtocolInPostSimple.h>
#include <plugserver/protocols/ProtocolInTrivial.h>
#include <plugserver/protocols/ProtocolInGetIterator.h>
#include <plugserver/protocols/ProtocolInGet.h>
#include <plugserver/protocols/ProtocolInPost.h>
#include <plugserver/protocols/ProtocolInPostKeysIterator.h>
#include <plugserver/protocols/ProtocolInPostKeys.h>

#include <plugserver/protocols/ProtocolInPostPairsIterator.h>
#include <plugserver/protocols/ProtocolInPostPairs.h>

// Listeners
#include <plugserver/listeners/RequestBase.h>


// Extensions
#include <plugserver/Extension.h>


#define PLUGIN extern "C" void plugin

#endif // PLUGSERVER_API_H

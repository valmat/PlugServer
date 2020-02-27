#ifndef PLUGSERVER_API_H
#define PLUGSERVER_API_H

#include <version.h>

// C++ headers
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#include <vector>
#include <unordered_map>
#include <map>
#include <forward_list>
#include <memory>

namespace rocksdb {
    using Slice = std::string_view;
}

// C headers
#include <string.h>

// Type traits
#include <traits.h>

// Server wrapper
#include <evhttp/EvResponse.h>
#include <evhttp/PostData.h>
#include <evhttp/EvRequest.h>
#include <evhttp/EvServerOptions.h>
#include <evhttp/EvLogger.h>

// Configs
#include <IniValue.h>
#include <IniConfigs.h>
#include <DefaultConfigs.h>

// Protocol
#include <protocols/ProtocolOut.h>
#include <protocols/ProtocolInPostSimple.h>
#include <protocols/ProtocolInTrivial.h>
#include <protocols/ProtocolInGetIterator.h>
#include <protocols/ProtocolInGet.h>
#include <protocols/ProtocolInPost.h>
#include <protocols/ProtocolInPostKeysIterator.h>
#include <protocols/ProtocolInPostKeys.h>

#include <protocols/ProtocolInPostPairsIterator.h>
#include <protocols/ProtocolInPostPairs.h>

// Listeners
#include <listeners/RequestBase.h>


// Extensions
#include <Extension.h>


#define PLUGIN extern "C" void plugin

#endif // PLUGSERVER_API_H

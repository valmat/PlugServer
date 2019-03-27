/**
 *  PlugServer.h
 *
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

#include "include/version.h"

// C++ headers
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

namespace rocksdb {
    using Slice = std::string_view;
    // struct Slice : std::string_view
    // {
    //     std::string ToString() const
    //     {
    //         return std::string(data(), size());
    //     }
    // };
}


#include <vector>
#include <unordered_map>
#include <map>
#include <forward_list>

#include <memory>
// std::unique_ptr

// C headers
#include <string.h>
#include <signal.h>
// C headers for `getrlimit()`
#include <sys/resource.h>

// Libevent
#include <event.h>
#include <event2/http.h>
#include <event2/http_struct.h>

// Type traits
#include "include/traits.h"

// Server wrapper
#include "include/evhttp/EvResponse.h"
#include "include/evhttp/PostData.h"
#include "include/evhttp/EvRequest.h"
#include "include/evhttp/EvServerOptions.h"
#include "include/evhttp/EvLogger.h"

// Configs
#include "IniValue.h"
#include "IniConfigs.h"
using vlm::IniConfigs;
using vlm::IniValue;

#include "include/DefaultConfigs.h"

// Protocol
#include "include/protocols/ProtocolOut.h"

#include "include/protocols/ProtocolInPostSimple.h"
#include "include/protocols/ProtocolInTrivial.h"
#include "include/protocols/ProtocolInGetIterator.h"
#include "include/protocols/ProtocolInGet.h"
#include "include/protocols/ProtocolInPost.h"
#include "include/protocols/ProtocolInPostKeysIterator.h"
#include "include/protocols/ProtocolInPostKeys.h"

#include "include/protocols/ProtocolInPostPairsIterator.h"
#include "include/protocols/ProtocolInPostPairs.h"

// Listeners
#include "include/listeners/RequestBase.h"


#include "include/evhttp/EvServer.h"

// Extensions
#include "include/Extension.h"
#include "extend/PlugContainer.h"
#include "extend/Extend.h"


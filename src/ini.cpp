#include "PlugServer.h"

template<>
vlm::IniValueString::operator IniValue<PlugServer::EvLogger::Level> () const {
    auto value = this->toString();
    if("debug" == value) return PlugServer::EvLogger::Level::debug;
    if("msg"   == value) return PlugServer::EvLogger::Level::msg;
    if("warn"  == value) return PlugServer::EvLogger::Level::warn;
    if("error" == value) return PlugServer::EvLogger::Level::error;
    if("fatal" == value) return PlugServer::EvLogger::Level::fatal;
    
    return PlugServer::EvLogger::Level::none;
}

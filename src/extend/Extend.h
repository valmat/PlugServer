/**
 *
 *  Extend.h
 *  Extend PlugServer
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

#pragma once

namespace PlugServer {

    class Extend
    {
    public:
        void load(EvServer &server, const IniConfigs &cfg, const DefaultConfigs &dfCfg);

    private:
        std::forward_list<PlugContainer> handles;
    };

}
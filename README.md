# Plugable server


PlugServer is my fork of RocksServer from which I deleted rocksdb.

## Dependency
[LibEvent](http://libevent.org/)
[IniConfigs](https://github.com/valmat/IniConfigs/),

The compiler should support `C++17`

## Install & Run

Clone the repository:
```
git clone --recursive https://github.com/valmat/PlugServer
cd PlugServer
```
or
```
git clone https://github.com/valmat/PlugServer
cd PlugServer
git submodule update
```
After then compile dependencies:
```
./deps/make.sh
```

Compile:
```
cd src
make
```

After:
edit config.ini and run

```
./PlugServer.bin config.ini
```

Or you can install it:

switch to root and run
```
make install
```

## How to extend
First you need implement your own request listener.
To do this, you should to implement the interface
```c
template<typename ProtIn, typename ProtOut>
struct RequestBase: public RequestSuperBase
{
    virtual void run(const ProtIn &, const ProtOut &) = 0;
};
```

For example:
`RequestPing.h`
```c
struct RequestPing : public RequestBase<ProtocolInTrivial, ProtocolOut>
{
    virtual void run(const ProtocolInTrivial &in, const ProtocolOut &out) override
    {
        out.setStr("pong");
    }
};
```
After that, you need to implement a plugin:
`smpl_plug.cpp`
```c
#include <plugserver/api.h>
#include "RequestPing.h"

PLUGIN(Extension &extension)
{
    extension.bind("/ping", new RequestPing());
}
```
Compile your plugin:
```
g++ -I. -I"/usr/include/plugserver/include" -Wall -O3 -std=c++11 -fPIC -c smpl_plug.cpp -o smpl_plug.o
g++ -Wall -std=c++11 -O3 -shared smpl_plug.o -o smpl_plug.so
```
and copy to `/usr/lib/plugserver/plugins`
```
cp -f smpl_plug.so /usr/lib/plugserver/plugins/smpl_plug.so
```
Restart RocksServer.
See [example](https://github.com/valmat/RocksServer/tree/master/extension_example) how to extend RocksServer.

## How to customize
Just edit [config.ini](https://github.com/valmat/RocksServer/blob/master/src/config.ini)

## License
[BSD](LICENSE)

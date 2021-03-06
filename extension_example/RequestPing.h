/**
 *  RequestPing.h
 *
 *  Simplest example request listener
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */


namespace PlugServer {

    struct RequestPing : public RequestBase<ProtocolInTrivial, ProtocolOut>
    {
        /**
         *  Runs request listener
         *  @param       protocol in object
         *  @param       protocol out object
         */
        virtual void run(const ProtocolInTrivial &/*in*/, const ProtocolOut &out) noexcept final
        {
            // Just set string to buffer output
            out.setStr("pong");
        }
        
        virtual ~RequestPing() = default;
    };
}

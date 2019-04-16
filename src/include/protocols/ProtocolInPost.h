 /**
 *  ProtocolInPost.h
 *
 *  Bridge to work with  a request.
 *  For http method POST
 *
 *  If the request http method is the POST 
 *  and you just need to get data such as key or key-value pair, use this class
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */


namespace PlugServer {

    class ProtocolInPost
    {
    public:
        ProtocolInPost(const EvRequest &r) :request(r), _raw(request.getPostData()) {}

        // Check query
        bool check(const ProtocolOut &out) const
        {
            // Detect if current method is POST
            if(!check()) {
                out.fail();
                return false;
            }
            return true;
        }

        bool check() const
        {
            // Detect if current method is POST
            if(!request.isPost()) {
                EvLogger::writeLog("Request method should be POST");
                return false;
            }

            // Check if POST data is empty
            if(_raw.empty()) {
                EvLogger::writeLog("Request POST data is empty");
                return false;
            }

            return true;
        }

        // retrive key
        std::string_view key() const
        {
            return _raw.toSlice();
        }
        std::string_view raw() const
        {
            return _raw.toSlice();
        }

        // retrive key and value
        std::pair<std::string_view, std::string_view> pair() const
        {
            std::string::size_type lpos = 0;
            std::string::size_type rpos = _raw.find('\n');
            std::string_view key(_raw, rpos);
            
            lpos = rpos+1;
            rpos = _raw.find('\n', lpos);
            auto vallen = std::atoll(_raw.data() + lpos);
            lpos = rpos+1;
            std::string_view value(_raw.data() + lpos, vallen);

            return std::make_pair(key, value);
        }

    protected:
        const EvRequest &request;
        const PostData _raw;
    };

}

/**
 *  ProtocolInPostPairsIterator.h
 *
 *  This is an internal helper class that is used when iterating over a keys
 *
 *  Thus, when you do c++ things like "for (auto &iter : prot_in)", internally
 *  a ProtocolInPostPairsIterator object is being used.
 *
 *  @author valmat <ufabiz@gmail.com>
 *  @github https://github.com/valmat/PlugServer
 */

namespace PlugServer {

    class ProtocolInPostPairsIterator
    {
    public:

        typedef std::string::size_type size_type;

        ProtocolInPostPairsIterator(const PostData &raw) :
            raw(raw)
        {
            if(lpos < raw.size()) {
                next();
            }
        }

        /**
         *  Trivial constructor (for returning in method ProtocolInPostPairs::end())
         */
        ProtocolInPostPairsIterator() :
            raw(std::move(PostData())),
            lpos(npos)
        {}

        /**
         *  Increment position (pre-increment)
         */
        ProtocolInPostPairsIterator &operator++()
        {
            next();
            return *this;
        }
        
        /**
         *  Increment position (post-increment)
         */
        ProtocolInPostPairsIterator operator++(int)
        {
            ProtocolInPostPairsIterator copy(*this);
            ++(*this);
            return copy;
        }
        
        /**
         *  Compare with other iterator
         */
        bool operator!=(const ProtocolInPostPairsIterator &that) const
        {
            return (lpos != that.lpos);
        }
        
        /**
         *  Compare with other iterator
         */
        bool operator==(const ProtocolInPostPairsIterator &that) const
        {
            return (lpos == that.lpos);
        }

        /**
         *  Derefecence, this returns a rocksdb::Slice with the current key
         */
        const std::pair<rocksdb::Slice, rocksdb::Slice> & operator*() const
        {
            return current;
        }
        
        /**
         *  Derefecence, this returns a rocksdb::Slice with the current key
         */
        const std::pair<rocksdb::Slice, rocksdb::Slice> * operator->() const
        {
            return &current;
        }

    private:

        /**
         *  Retrive current
         */
        void next()
        {
            if(lpos >= raw.size()) {
                lpos = npos;
                return;
            }

            // retrive key
            rpos = raw.find('\n', lpos);
            size_type key_star = lpos;
            size_type key_len  = rpos - lpos;
            
            // retrive value
            lpos = rpos+1;

            rpos = raw.find('\n', lpos);
            size_type vallen = std::atol(raw.data() + lpos);
            lpos = rpos+1;

            // set pair
            current = std::make_pair(rocksdb::Slice(raw.data() + key_star, key_len), rocksdb::Slice(raw.data() + lpos, vallen));

            //to next iteration
            lpos += vallen + 1;
        }

        constexpr static size_type npos = std::string::npos;

        const PostData &raw;
        std::pair<rocksdb::Slice, rocksdb::Slice> current;
        
        size_type lpos = 0;
        size_type rpos = 0;
    };
}

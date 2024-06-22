#ifndef ZELDA_TEXTURE_POOL_HPP
#define ZELDA_TEXTURE_POOL_HPP
#include <unordered_map>
#include <raylib.h>
#include <thread>
#include <mutex>


namespace ze {


    class TexturePool {

        private:
            std::unordered_map<unsigned long, Texture2D> textureMap;
            std::mutex m;        
        
        public:
            TexturePool();
            ~TexturePool();
            Texture2D load(const char* file_name);            
            void erase(const char* file_name);
            void clear();
            std::size_t size() const;

    };

    inline ze::TexturePool gTexturePool{};
    
} // namespace ze



#endif
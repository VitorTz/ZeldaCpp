#ifndef ZELDA_TEXTURE_POOL_HPP
#define ZELDA_TEXTURE_POOL_HPP
#include <raylib.h>
#include <unordered_map>
#include <array>


namespace ze {


    class TexturePool {

        private:
            std::unordered_map<unsigned long, Texture2D> textureMap{};
            
        public:
            TexturePool();
            ~TexturePool();
            void loadDir(const char* dir, bool recursive);
            Texture2D load(const char* file_name);
            void erase(const char* file_name);
            void clear();
            std::size_t size() const;

    };

    inline ze::TexturePool gTexturePool{};
    
} // namespace ze



#endif
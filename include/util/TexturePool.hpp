#ifndef F9C4E9DC_2914_44C1_917E_FD4CB92F98BB
#define F9C4E9DC_2914_44C1_917E_FD4CB92F98BB
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <memory>
#include <map>


namespace ze {

    class TexturePool {

        private:
            static std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> textureMap;
        
        public:
            static void load(sf::Sprite* sprite, const std::filesystem::path& source);
            inline static void erase(const std::filesystem::path& source) { ze::TexturePool::textureMap.erase(source); }


    };

    
} // namespace ze 


#endif /* F9C4E9DC_2914_44C1_917E_FD4CB92F98BB */

#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <filesystem>
#include <memory>
#include <map>



namespace ze {

    typedef std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> TextureMap;

    class TexturePool {

        private:
            static ze::TextureMap textureMap;
        
        public:
            static void load(sf::Sprite* sprite, const std::filesystem::path& source);
            static void erase(const std::filesystem::path& source);

    };
    
} // namespace ze

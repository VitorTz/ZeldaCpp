#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>


namespace ze {


    class TexturePool {

        private:
            static std::map<std::string, sf::Texture*> textures;

        public:
            static sf::Texture* load(const std::string& path);
            static void rmv(const std::string& path);
            static void rmvAll();

    };

    
} // namespace ze

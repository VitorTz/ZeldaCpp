//
// Created by vitor on 1/28/24.
//

#ifndef ZELDACPP_TEXTUREPOOL_H
#define ZELDACPP_TEXTUREPOOL_H
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
        static void erase(const std::filesystem::path& source);
        static void clear();

    };

}



#endif //ZELDACPP_TEXTUREPOOL_H

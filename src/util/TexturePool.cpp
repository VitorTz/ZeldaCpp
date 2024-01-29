#include "../../include/util/TexturePool.hpp"



std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> ze::TexturePool::textureMap;



void ze::TexturePool::load(sf::Sprite* sprite, const std::filesystem::path& source) {
    if (ze::TexturePool::textureMap.find(source) == ze::TexturePool::textureMap.end()) {
        const auto& [pair, success] = ze::TexturePool::textureMap.insert(
            {
                source,
                std::make_unique<sf::Texture>()
            }
        );
        pair->second->setSmooth(true);
        pair->second->loadFromFile(source);
    }
    sprite->setTexture(*ze::TexturePool::textureMap.at(source).get());
}

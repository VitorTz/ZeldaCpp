#include "../../include/util/texture_pool.hpp"


std::map<std::string, std::unique_ptr<sf::Texture>> ze::TexturePool::textureMap;


void ze::TexturePool::load(sf::Sprite& sprite, const ze::ImageSource& source) {    
    if (ze::TexturePool::textureMap.find(source.path) == ze::TexturePool::textureMap.end()) {
        const auto& [pair, success] = ze::TexturePool::textureMap.insert(
            {source.path, std::make_unique<sf::Texture>()}
        );
        
        pair->second->loadFromFile(source.path);
    }
    
    sf::Texture* texture = ze::TexturePool::textureMap.at(source.path).get();
    if (!source.isMask) {
        sprite.setTexture(*texture);
        return;
    }

    const std::string maskKey = "mask-" + source.path;
    if (ze::TexturePool::textureMap.find(maskKey) == ze::TexturePool::textureMap.end()) {
        sf::Image image = texture->copyToImage();
        const sf::Vector2u imageSize = image.getSize();

        for (std::size_t j = 0; j < imageSize.y; j++) {
            for (std::size_t i = 0; i < imageSize.x; i++) {
                const sf::Color c = image.getPixel(i, j);
                if (c.a != 0) image.setPixel(i, j, source.maskColor);                
            }
        }
        
        const auto& [pair, success] = ze::TexturePool::textureMap.insert(
            {maskKey, std::make_unique<sf::Texture>()}
        );
        
        pair->second->loadFromImage(image);
    }

    sf::Texture* maskTexture = ze::TexturePool::textureMap.at(maskKey).get();
    sprite.setTexture(*maskTexture);

}


void ze::TexturePool::rmv(const std::string& path) {
    ze::TexturePool::textureMap.erase("mask-" + path);
    ze::TexturePool::textureMap.erase(path);
}
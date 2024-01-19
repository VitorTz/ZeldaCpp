#include "../../include/util/texture_pool.hpp"


std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> ze::TexturePool::textureMap;


std::mutex ze::TexturePool::m;


std::unique_ptr<sf::Texture>& ze::TexturePool::addTexture(const std::filesystem::path& path) {
    ze::TexturePool::m.lock();
    if (ze::TexturePool::textureMap.find(path) == ze::TexturePool::textureMap.end()) {        
        const auto& [pair, success] = ze::TexturePool::textureMap.insert(
            {path, std::make_unique<sf::Texture>()}
        );        
        pair->second->loadFromFile(path);
    }
    std::unique_ptr<sf::Texture>& t = ze::TexturePool::textureMap.at(path);
    ze::TexturePool::m.unlock();
    return t;
}

void ze::TexturePool::load(sf::Sprite& sprite, const std::filesystem::path& path) {
    std::unique_ptr<sf::Texture>& t = ze::TexturePool::addTexture(path);
    sprite.setTexture(*t.get());
}


void ze::TexturePool::rmv(const std::filesystem::path& path) {
    ze::TexturePool::m.lock();
    ze::TexturePool::textureMap.erase(path);
    ze::TexturePool::m.unlock();
}


void ze::TexturePool::rmvAll() {
    ze::TexturePool::m.lock();
    ze::TexturePool::textureMap.clear();
    ze::TexturePool::m.unlock();
}
#include "../../include/util/texture_pool.hpp"


std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> og::TexturePool::textureMap;


std::mutex og::TexturePool::m;


std::unique_ptr<sf::Texture>& og::TexturePool::addTexture(const std::filesystem::path& path) {
    og::TexturePool::m.lock();
    if (og::TexturePool::textureMap.find(path) == og::TexturePool::textureMap.end()) {        
        const auto& [pair, success] = og::TexturePool::textureMap.insert(
            {path, std::make_unique<sf::Texture>()}
        );        
        pair->second->loadFromFile(path);
    }
    std::unique_ptr<sf::Texture>& t = og::TexturePool::textureMap.at(path);
    og::TexturePool::m.unlock();
    return t;
}

void og::TexturePool::load(sf::Sprite& sprite, const std::filesystem::path& path) {
    std::unique_ptr<sf::Texture>& t = og::TexturePool::addTexture(path);
    sprite.setTexture(*t.get());
}


void og::TexturePool::rmv(const std::filesystem::path& path) {
    og::TexturePool::m.lock();
    og::TexturePool::textureMap.erase(path);
    og::TexturePool::m.unlock();
}


void og::TexturePool::rmvAll() {
    og::TexturePool::m.lock();
    og::TexturePool::textureMap.clear();
    og::TexturePool::m.unlock();
}
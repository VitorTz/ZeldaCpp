#include "../../include/util/texture_pool.hpp"



std::map<std::string, sf::Texture*>  ze::TexturePool::textures;


sf::Texture* ze::TexturePool::load(const std::string& path) {
    if (ze::TexturePool::textures.find(path) == ze::TexturePool::textures.end()) {
        sf::Texture* t = new sf::Texture();
        t->setSmooth(true);
        t->loadFromFile(path);
        ze::TexturePool::textures.insert({path, t});
    }
    return ze::TexturePool::textures.at(path);
}


void ze::TexturePool::rmv(const std::string& path) {
    if (ze::TexturePool::textures.find(path) != ze::TexturePool::textures.end()) {
        sf::Texture* t = ze::TexturePool::textures.at(path);
        delete t;
        ze::TexturePool::textures.erase(path);
    }
}


void ze::TexturePool::rmvAll() {
    for (const auto& pair : ze::TexturePool::textures)
        delete pair.second;
    ze::TexturePool::textures.clear();
}
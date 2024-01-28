//
// Created by vitor on 1/28/24.
//
#include "../../include/util/TexturePool.h"


std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> ze::TexturePool::textureMap;


void ze::TexturePool::load(sf::Sprite *sprite, const std::filesystem::path &source) {
    if (ze::TexturePool::textureMap.find(source) == ze::TexturePool::textureMap.end()) {
        const auto& [pair, success] = ze::TexturePool::textureMap.insert({source, std::make_unique<sf::Texture>()});
        pair->second->setSmooth(true);
        pair->second->loadFromFile(source);
    }
    sprite->setTexture(*ze::TexturePool::textureMap.at(source).get());
}


void ze::TexturePool::erase(const std::filesystem::path &source) {
    ze::TexturePool::textureMap.erase(source);
}


void ze::TexturePool::clear() {
    ze::TexturePool::textureMap.clear();
}
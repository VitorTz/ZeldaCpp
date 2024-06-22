#include "texture_pool.hpp"
#include "util.hpp"


ze::TexturePool::TexturePool() {
    this->textureMap.reserve(256);
}


ze::TexturePool::~TexturePool() {
    for (auto& pair : this->textureMap) {
        UnloadTexture(pair.second);
    }
}


Texture2D ze::TexturePool::load(const char* file_name) {
    const unsigned long h = ze::hash(file_name);
    if (this->textureMap.find(h) == this->textureMap.end()) {        
        this->textureMap.insert({h, LoadTexture(file_name)});
    }
    return this->textureMap[h];
}


void ze::TexturePool::erase(const char* file_name) {
    const unsigned long h = ze::hash(file_name);
    this->textureMap.erase(h);
}


void ze::TexturePool::clear() {
    for (auto& pair : this->textureMap) {
        UnloadTexture(pair.second);
    }
    this->textureMap.clear();
}


std::size_t ze::TexturePool::size() const {
    return this->textureMap.size();
}
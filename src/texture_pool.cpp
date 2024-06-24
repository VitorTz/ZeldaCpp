#include <filesystem>
#include "texture_pool.hpp"
#include "util.hpp"


const std::filesystem::path pngExtension{".png"};

const std::filesystem::path jpegExtension{".jpeg"};


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


void ze::TexturePool::loadDir(const char* dir, const bool recursive) {    
    for (auto& p : std::filesystem::directory_iterator(dir)) {
        const std::filesystem::path path = p.path();
        const std::filesystem::path extension = path.extension();
        if (
            std::filesystem::is_regular_file(p) &&
            extension == pngExtension ||
            extension == jpegExtension
        ) {
            this->load(path.c_str());
        } else if (recursive && std::filesystem::is_directory(path)) {
            this->loadDir(path.c_str(), true);
        }
    }
}


void ze::TexturePool::erase(const char* file_name) {
    const unsigned long h = ze::hash(file_name);
    if (this->textureMap.find(h) != this->textureMap.end()) {
        UnloadTexture(this->textureMap[h]);
    }
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
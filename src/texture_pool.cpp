#include "texture_pool.h"
#include "util.h"


ze::TexturePool::TexturePool() {
	this->textureMap.reserve(256 / static_cast<std::size_t>(this->textureMap.max_load_factor()));
}


ze::TexturePool::~TexturePool() {
	for (auto& pair : this->textureMap) {
		UnloadTexture(pair.second);
	}
}


Texture2D ze::TexturePool::load(const char* file_name) {
	const unsigned long h = ze::hash_f(file_name);
	if (this->textureMap.find(h) == this->textureMap.end()) {
		this->textureMap.insert({ h, LoadTexture(file_name) });
	}
	return this->textureMap[h];
}


void ze::TexturePool::erase(const char* file_name) {
	const unsigned long h = ze::hash_f(file_name);
	if (this->textureMap.find(h) != this->textureMap.end()) {
		UnloadTexture(this->textureMap[h]);
		this->textureMap.erase(h);
	}
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
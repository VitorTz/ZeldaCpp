#pragma once
#include <unordered_map>
#include <raylib.h>


namespace ze {


	class TexturePool {

	private:
		std::unordered_map<unsigned long, Texture2D> textureMap{};

	public:
		TexturePool();
		~TexturePool();
		Texture2D load(const char* file_name);
		void erase(const char* file_name);
		void clear();
		std::size_t size() const;

	};

	inline ze::TexturePool gTexturePool{};

}
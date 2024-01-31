#ifndef F90A8A5B_98DA_4F7A_AB07_C2DD00232198
#define F90A8A5B_98DA_4F7A_AB07_C2DD00232198
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>
#include <memory>
#include <map>


namespace ze {

    typedef std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> TextureMap;

    class TexturePool {

        private:
            static TextureMap textureMap;
        
        public:
            static void load(sf::Sprite* sprite, const std::filesystem::path& source);
            static void erase(const std::filesystem::path& source);

    };

    
} // namespace ze


#endif /* F90A8A5B_98DA_4F7A_AB07_C2DD00232198 */

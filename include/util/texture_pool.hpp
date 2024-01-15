#ifndef FC1808FF_4FE9_44D1_8D8E_D291305F03EA
#define FC1808FF_4FE9_44D1_8D8E_D291305F03EA
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>
#include <memory>
#include <map>


namespace ze {


    typedef struct ImageSource {
        const std::string path;
        const bool isMask = {false};
        const sf::Color maskColor = { };
    } ImageSource;

    typedef std::map<std::string, std::unique_ptr<sf::Texture>> TextureMap;

    class TexturePool {

        private:
            static TextureMap textureMap;
            
        public:
            static void load(sf::Sprite& sprite, const ze::ImageSource& imageSource);
            static void rmv(const std::string& path);

    };
    
} // namespace ze


#endif /* FC1808FF_4FE9_44D1_8D8E_D291305F03EA */

#ifndef E50F8321_8EBE_4C2A_B4AA_0E63015892B5
#define E50F8321_8EBE_4C2A_B4AA_0E63015892B5
#include <mutex>
#include <filesystem>
#include <map>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace ze{ 


    class TexturePool {

        private:
            static std::mutex m;
            static std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> textureMap;
            static std::unique_ptr<sf::Texture>& addTexture(const std::filesystem::path& path);

        public:
            static void load(sf::Sprite& sprite, const std::filesystem::path& path);
            static void rmv(const std::filesystem::path& path);
            static void rmvAll();

    


    };
    
} // namespace ze


#endif /* E50F8321_8EBE_4C2A_B4AA_0E63015892B5 */

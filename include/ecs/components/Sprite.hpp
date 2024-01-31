#ifndef B51AB959_CC80_44A1_A16A_27AD7F368788
#define B51AB959_CC80_44A1_A16A_27AD7F368788
#include <filesystem>
#include "../../util/TexturePool.hpp"
#include "../GameObj.hpp"


namespace ze {


    class Sprite : public ze::Component {

        private:
            std::filesystem::path source;
            sf::Sprite sprite;

        public:
            Sprite(const std::filesystem::path& source);
            virtual ~Sprite();
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;

    };
    
} // namespace ze


#endif /* B51AB959_CC80_44A1_A16A_27AD7F368788 */

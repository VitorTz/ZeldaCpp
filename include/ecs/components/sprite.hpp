#ifndef D5DBAFBA_B1C7_4F1A_8E6B_61A8F2EB7DEB
#define D5DBAFBA_B1C7_4F1A_8E6B_61A8F2EB7DEB
#include <filesystem>
#include "../ecs.hpp"
#include "../../util/texture_pool.hpp"


namespace og {


    class Sprite : public og::Component {

        private:
            std::filesystem::path path;
            sf::Sprite sprite;

        public:
            explicit Sprite(
                const std::filesystem::path& path
            );
            Sprite(
                const std::string& name,
                const std::filesystem::path& path
            );
            void draw(sf::RenderWindow& window) override;
            void setGameObj(og::GameObj* gameObj) override;

    };
    
} // namespace og


#endif /* D5DBAFBA_B1C7_4F1A_8E6B_61A8F2EB7DEB */

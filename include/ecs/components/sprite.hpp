#ifndef D5DBAFBA_B1C7_4F1A_8E6B_61A8F2EB7DEB
#define D5DBAFBA_B1C7_4F1A_8E6B_61A8F2EB7DEB
#include <filesystem>
#include "../ecs.hpp"
#include "../../util/texture_pool.hpp"


namespace ze {


    class Sprite : public ze::Component {

        private:
            std::filesystem::path path;
            sf::Sprite sprite;
            const sf::Vector2f boxColliderScale;

        public:
            Sprite(Sprite&& ) = default;
            Sprite(const ze::MapObj& mapObjId);
            Sprite(const std::filesystem::path& path);
            Sprite(
                const std::filesystem::path& path,
                const sf::Vector2f& boxColliderScale
            );
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;

    };
    
} // namespace ze


#endif /* D5DBAFBA_B1C7_4F1A_8E6B_61A8F2EB7DEB */

#pragma once
#include <filesystem>
#include "../Ecs.hpp"
#include "../../util/TexturePool.hpp"


namespace ze {

    class Sprite : public ze::Component {

        private:
            const std::filesystem::path source;
            sf::Sprite sprite;

        public:
            Sprite(const std::filesystem::path& source);
            ~Sprite() override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;

    };
    
} // namespace ze

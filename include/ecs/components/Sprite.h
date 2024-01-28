//
// Created by vitor on 1/28/24.
//
#ifndef ZELDACPP_SPRITE_H
#define ZELDACPP_SPRITE_H
#include "../ecs.h"
#include "../../util/TexturePool.h"


namespace ze {

    class Sprite : public ze::Component {

    private:
        std::filesystem::path source;
        sf::Sprite sprite;

    public:
        explicit Sprite(const std::filesystem::path& source);
        ~Sprite() override;
        void draw(sf::RenderWindow& window) override;
        void setGameObj(ze::GameObj* gameObj) override;

    };


}

#endif //ZELDACPP_SPRITE_H

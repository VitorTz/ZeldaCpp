//
// Created by vitor on 1/28/24.
//

#ifndef ZELDACPP_CAMERA_H
#define ZELDACPP_CAMERA_H
#include "../ecs/ecs.h"
#include <algorithm>

namespace ze {

    class Camera : public ze::Group {

    private:
        static void sortObjsByYpos(std::vector<ze::GameObj*>& v);

    private:
        std::map<int, std::vector<ze::GameObj*>> gameObjsByIndex;

    public:
        Camera() : ze::Group(ze::GroupId::CameraGroup) { }
        void update([[maybe_unused]] float dt) override { };
        void add(ze::GameObj* gameObj) override;
        void rmv(ze::GameObj* gameObj) override;
        void rmvAll() override;
        void draw(sf::RenderWindow& window, sf::Vector2f offset);

    };

}

#endif //ZELDACPP_CAMERA_H

//
// Created by vitor on 1/28/24.
//

#ifndef ZELDACPP_LEVEL_H
#define ZELDACPP_LEVEL_H
#include "Scene.h"
#include "../window/Camera.h"


namespace ze {


    class Level : public ze::Scene {

    public:
        explicit Level(const ze::ChangeScene &changeScene);
        void update(float dt) override;
        void render(sf::RenderWindow& window) override;

    };

}

#endif //ZELDACPP_LEVEL_H

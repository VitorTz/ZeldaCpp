//
// Created by vitor on 1/28/24.
//
#include "../../include/scene/Level.h"


ze::Level::Level(
    const ze::ChangeScene &changeScene
) : ze::Scene(ze::SceneId::LevelId, changeScene) {

    // create groups
    ze::GameObjPool::clear();
    ze::GroupPool::clear();
    ze::GroupPool::create(
        {
            ze::GroupId::CollideGroup,
            ze::GroupId::AllGroup,
            ze::GroupId::TreesGroup
        }
    );
    ze::GroupPool::create(std::make_unique<ze::Camera>());

    // create objs

    ze::GameObj* player = ze::GameObjPool::create(
            "Player",
            1,
            {ze::GroupId::AllGroup, ze::GroupId::CameraGroup}
    );
    player->addComponent(std::make_unique<ze::Sprite>("/mnt/HD/Imagens/wallpapers/0.png"));

}


void ze::Level::update(float dt) {
    ze::GroupPool::get(ze::GroupId::AllGroup)->update(dt);
}


void ze::Level::render(sf::RenderWindow &window) {
    auto *camera = (ze::Camera*) ze::GroupPool::get(ze::GroupId::CameraGroup);
    camera->draw(window, {0, 0});
}
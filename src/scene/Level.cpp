#include "../../include/scene/Level.hpp"


ze::Level::Level(
    const ze::ChangeScene& changeScene 
) : ze::Scene(ze::SceneId::LevelScene, changeScene) {
    ze::GameObj* player =  ze::Ecs::gameObjPool->insert(
        "Player", 
        1,
        ze::Ecs::groupPool.get(),
        {ze::GroupId::CameraGroup}
    );
    player->addComponent(
        std::make_unique<ze::Sprite>(
            "/run/media/HD/Imagens/wallpapers/2.png"
        )
    );
}


void ze::Level::update(const float dt) {
    ze::Ecs::gameObjPool->update(dt);
}


void ze::Level::draw(sf::RenderWindow& window) {
    ze::GameObj* player = ze::Ecs::gameObjPool->at("Player");
    ze::Camera* camera = (ze::Camera*) ze::Ecs::groupPool->at(ze::GroupId::CameraGroup);
    camera->draw(window, player->transform.center());
}
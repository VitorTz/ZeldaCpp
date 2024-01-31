#include "../../include/scene/Level.hpp"


ze::Level::Level(
    const ze::ChangeScene& changeScene
) : ze::Scene(ze::SceneId::LevelSceneId, changeScene) {    

    this->gameObjPool.create(
        "Ground",
        ze::Zindex::GroundIndex,
        {ze::GroupId::CameraGroup},
        std::make_unique<ze::Sprite>("/mnt/HD/Programs/vitor/ZeldaCpp/res/graphics/tilemap/ground.png")
    );
    
    this->gameObjPool.create(
        "Player", 
        ze::Zindex::PlayerIndex, 
        {ze::GroupId::AllGroup, ze::GroupId::CameraGroup},
        std::make_unique<ze::Sprite>("/mnt/HD/Programs/vitor/ZeldaCpp/res/graphics/player/down_idle/idle_down.png")
    );

    ze::GameObj* player = this->gameObjPool.get("Player");
    player->direction = {1.f, 1.f};
    player->speed = 250.f;
    
}


void ze::Level::update(const float dt) {
    this->gameObjPool.get("Player")->move(dt);
    this->gameObjPool.getGroup(ze::GroupId::AllGroup)->update(dt);
}


void ze::Level::draw(sf::RenderWindow& window) {
    ze::Camera* camera = (ze::Camera*) this->gameObjPool.getGroup(ze::GroupId::CameraGroup);
    ze::GameObj* player = this->gameObjPool.get("Player");    
    camera->draw(window, player->rect.center());
}
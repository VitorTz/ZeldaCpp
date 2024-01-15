#include "../../include/scene/level.hpp"


ze::Level::Level(
    const ze::ChangeScene& changeScene 
) : ze::Scene(ze::SceneId::LevelId, changeScene),
    player(std::make_shared<ze::GameObj>("Player", ze::Zindex::PlayerIndex)) {
    
    ze::Camera* camera = (ze::Camera*) this->groups.at("camera").get();
    camera->setOffset(this->player);
    
    this->addToGroup(player, {"camera", "all"});
    this->player->addComponent(new ze::Player());

    std::shared_ptr<ze::GameObj> ground = std::make_shared<ze::GameObj>("Ground", ze::Zindex::GroundIndex);
    ground->addComponent(new ze::Sprite({ze::GROUND_IMAGE_FILE}));
    this->addToGroup(ground, {"camera"});
}


void ze::Level::update(const float dt) {
    ze::Scene::update(dt);

}
#include "../../include/scene/level.hpp"


ze::Level::Level(
    const ze::ChangeScene& changeScene 
) : ze::Scene(ze::SceneId::LevelId, changeScene) {
    std::unique_ptr<ze::GameObj> player = std::make_unique<ze::GameObj>("Player");
    player->addComponent(
        new ze::Mask(
            "Sprite",
            "res/graphics/player/left/left_0.png",
            sf::Color::White
        )
    );
    this->addGameObj(player);
}
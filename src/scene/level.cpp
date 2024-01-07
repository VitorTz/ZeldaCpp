#include "../../include/scene/level.hpp"



ze::Level::Level(
    const ze::ChangeScene& changeScene
) : ze::Scene(ze::SceneId::LevelId, changeScene) {
    ze::ougi::Player* player = new ze::ougi::Player();
    ze::ougi::Group* g = this->camera.getGroup(0);
    g->add(player);    
}
#include "../../include/scene/level.hpp"


og::Level::Level(
    const og::ChangeScene& changeScene
) : og::Scene(og::SceneId::LevelId, changeScene) {

}


void og::Level::update(const float dt) {
    og::Scene::update(dt);
}


void og::Level::draw(sf::RenderWindow& window) {
    og::Scene::draw(window);
}
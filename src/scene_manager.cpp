#include "scene_manager.h"


ze::SceneManager::SceneManager() {
	this->loadNextScene();
}


void ze::SceneManager::loadNextScene() {
	switch (this->scene_id) {
		case ze::TitleScreenId:
			this->scene = std::make_unique<ze::TitleScreen>();
			break;
		case ze::LevelSceneId:
			this->scene = std::make_unique<ze::LevelScene>();
			break;
		default:
			break;
	}
}


void ze::SceneManager::update() {
	this->scene->update(this->changeSceneRequest);	
}


void ze::SceneManager::draw() {
	this->scene->draw();
	if (this->should_change_scene == true) {
		this->should_change_scene = false;
		this->loadNextScene();
	}
}
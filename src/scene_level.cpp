#include "scene.h"
#include "ecs.h"
#include <random>


ze::LevelScene::LevelScene() {
	
}


void ze::LevelScene::update(const ze::ChangeScene& changeScene) {
	const float dt = GetFrameTime();	
	ze::gEcs.update(dt);
}


void ze::LevelScene::draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	ze::gEcs.draw();
	EndDrawing();
}
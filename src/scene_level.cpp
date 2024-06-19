#include "scene.h"
#include "ecs.h"
#include <random>


ze::LevelScene::LevelScene() {
	std::default_random_engine generator;
	std::uniform_real_distribution<float> randXPos(0, ZE_SCREEN_WIDTH);
	std::uniform_real_distribution<float> randYPos(-ZE_SCREEN_HEIGHT, 0);
	for (int i = 0; i < ZE_MAX_ENTITIES; i++) {
		const ze::Entity e = ze::gEcs.entityCreate(0, true);
		ze::gEcs.addComponent<ze::sprite_t>(e, ze::sprite_t{ ASSETS_PATH "icon/icon.png" });
		ze::transform_t& t = ze::gEcs.get_transform(e);
		t.pos.x = randXPos(generator);
		t.pos.y = randYPos(generator);
		t.direction.y = 1;
		t.speed = 150.0f;
	}
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
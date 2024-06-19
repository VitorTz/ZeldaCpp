#include "scene.h"
#include "texture_pool.h"
#include "constants.h"


ze::TitleScreen::TitleScreen(
) : logo(ze::gTexturePool.load(ASSETS_PATH "logo/logo.png")),
	font(LoadFontEx(ASSETS_PATH "font/The-Wild-Breath-of-Zelda.ttf", 52, 0, 255)) {
	std::array<const char*, 2> textures = {
		ASSETS_PATH "logo/background.png",
		ASSETS_PATH "logo/background1.png"
	};
	for (int i = 0; i < this->background.size(); i++) {
		this->background[i].first = ze::gTexturePool.load(textures[i]);
		this->background[i].second = {(float) (i * ZE_SCREEN_WIDTH), 0.0f };
	}	
}


void ze::TitleScreen::update(const ze::ChangeScene& changeScene) {
	const float dt = GetFrameTime();
	for (std::pair<Texture2D, Vector2>& pair : this->background) {
		pair.second.x -= dt * 100.0f;
		if (pair.second.x + ZE_SCREEN_WIDTH < 0) {
			pair.second.x += ZE_SCREEN_WIDTH * background.size();
		}
	}
	if (IsKeyPressed(KEY_SPACE)) {
		ze::gTexturePool.clear();
		changeScene(ze::LevelSceneId);
	}
}


void ze::TitleScreen::draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	for (std::pair<Texture2D, Vector2>& pair : this->background) {
		DrawTextureV(pair.first, pair.second, WHITE);
	}
	DrawTexture(
		logo, 
		ZE_SCREEN_WIDTH / 2 - logo.width / 2, 
		ZE_SCREEN_HEIGHT / 2 - logo.height / 2,
		WHITE
	);
	DrawTextEx(
		font, 
		"PRESS ENTER",
		{ ZE_SCREEN_WIDTH / 2.0f - 100, ZE_SCREEN_HEIGHT - 220.0f }, 
		52, 
		1.0f, 
		BLACK);
	EndDrawing();
}
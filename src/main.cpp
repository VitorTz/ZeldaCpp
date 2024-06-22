#include "constants.h"
#include "scene_manager.h"
#include "ecs.h"


int main() {
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(ZE_SCREEN_WIDTH, ZE_SCREEN_HEIGHT, ZE_WINDOW_TITLE);
	Image icon = LoadImage(ASSETS_PATH "icon/icon.png");
	SetWindowIcon(icon);

	ze::SceneManager sceneManager;

	while (WindowShouldClose() == false) {
		sceneManager.update();
		sceneManager.draw();
	}
	
	UnloadImage(icon);
	ze::gTexturePool.clear();
	CloseWindow();
	return 0;
}
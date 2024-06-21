#pragma once
#include "scene.h"
#include "constants.h"


namespace ze {

	class SceneManager {

	private:
		std::unique_ptr<ze::Scene> scene;
		ze::ChangeScene changeSceneRequest = [this](const ze::SceneId id) {
			this->should_change_scene = true;
			this->scene_id = id;
			};
		ze::SceneId scene_id = ZE_FIRST_SCENE;
		bool should_change_scene = false;

	private:
		void loadNextScene();

	public:
		SceneManager();
		void update();
		void draw();

	};

}

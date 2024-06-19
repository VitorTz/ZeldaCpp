#pragma once
#include <memory>
#include <functional>
#include <raylib.h>
#include <array>


namespace ze {


	enum SceneId {
		TitleScreenId,
		LevelSceneId
	};

	constexpr ze::SceneId first_scene = ze::SceneId::TitleScreenId;

	typedef std::function<void(ze::SceneId)> ChangeScene;

	class Scene {
		
	public:
		virtual ~Scene() = default;
		virtual void update(const ze::ChangeScene& changeScene) = 0;
		virtual void draw() = 0;

	};

	class SceneManager {

	private:
		std::unique_ptr<ze::Scene> scene;
		ze::ChangeScene changeSceneRequest = [this](const ze::SceneId id) {
			this->should_change_scene = true;
			this->scene_id = id;
		};
		ze::SceneId scene_id = ze::first_scene;
		bool should_change_scene = false;

	private:
		void loadNextScene();		

	public:
		SceneManager();
		void update();
		void draw();

	};


	class TitleScreen : public ze::Scene {

	private:
		std::array<std::pair<Texture2D, Vector2>, 2> background;
		Texture2D logo;
		Font font;

	public:
		TitleScreen();
		void update(const ze::ChangeScene& changeScene) override;
		void draw() override;

	};


	class LevelScene : public ze::Scene {

	public:
		LevelScene();
		void update(const ze::ChangeScene& changeScene) override;
		void draw() override;

	};

}
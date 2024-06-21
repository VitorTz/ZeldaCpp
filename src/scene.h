#pragma once
#include <raylib.h>
#include <memory>
#include <array>
#include "types.h"


namespace ze {


	constexpr ze::SceneId first_scene = ze::SceneId::LevelSceneId;	

	class Scene {
		
	public:
		virtual ~Scene() = default;
		virtual void update(const ze::ChangeScene& changeScene) = 0;
		virtual void draw() = 0;

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
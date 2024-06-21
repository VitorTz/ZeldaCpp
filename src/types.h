#pragma once
#include <cstdint>
#include <raylib.h>
#include <functional>
#include <utility>


namespace ze {


	typedef std::uint32_t entity;
	typedef std::uint8_t z_index;	
	typedef std::uint8_t component;


	enum SceneId {
		TitleScreenId,
		LevelSceneId
	};

	typedef std::function<void(ze::SceneId)> ChangeScene;
	
	enum Action {
		
		Left = 2 << 1,
		Right = 2 << 2,
		Down = 2 << 3,
		Up = 2 << 4,
		
		Idle = 2 << 5,

		Attack = 2 << 6,		
		
		LeftIdle = Left | Idle,
		LeftAttack = Left | Attack,

		RightIdle = Right | Idle,
		RightAttack = Right | Attack,

		UpIdle = Up | Idle,
		UpAttack = Up | Attack,

		DownIdle = Down | Idle,
		DownAttack = Down | Attack

	};

	enum AnimationSpeed {
		Slow = 4,
		Normal = 6,
		Fast = 8
	};

}
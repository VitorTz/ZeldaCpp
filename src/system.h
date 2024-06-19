#pragma once
#include <unordered_set>
#include "types.h"



namespace ze {


	class System {

	public:
		std::unordered_set<ze::Entity> entities{};

	public:
		virtual ~System() = default;
		virtual void update(float dt) = 0;
		virtual void draw(ze::Entity e) = 0;

	};

	class TransformSystem : public ze::System {

	public:
		void update(float dt) override;
		void draw(ze::Entity e) override;

	};

	class SpriteSystem : public ze::System {

	public:
		void update(float dt) override;
		void draw(ze::Entity e) override;

	};

	class ControllerSystem : public ze::System {

	public:
		void update(float dt) override;
		void draw(ze::Entity e) override;

	};

}
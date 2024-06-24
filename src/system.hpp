#ifndef ZELDA_SYSTEM_HPP
#define ZELDA_SYSTEM_HPP
#include <unordered_set>
#include "types.hpp"


namespace ze {


    class System {

        public:
            std::unordered_set<ze::entity_t> entities;

        public:
            virtual ~System() = default;
            virtual void update(float dt) = 0;
            virtual void draw(ze::entity_t e) = 0;
    };

    class TransformSystem : public ze::System {

        public:
            void update(float dt) override;
            void draw(ze::entity_t e) override;

    };

    class SpriteSystem : public ze::System {

        public:
            void update(float dt) override;
            void draw(ze::entity_t e) override;

    };

    class SpriteAnimationSystem : public ze::System {

        public:
            void update(float dt) override;
            void draw(ze::entity_t e) override;

    };

    class PlayerSystem : public ze::System {
        
        public:
            void update(float dt) override;
            void draw(ze::entity_t e) override;
    };
    
    
    class ObstacleSystem : public ze::System {
        
        public:
            void update(float dt) override;
            void draw(ze::entity_t e) override;
    };

} // namespace ze



#endif
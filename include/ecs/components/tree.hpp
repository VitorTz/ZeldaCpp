#ifndef BDEC60EA_9D6B_4DEA_B3DC_4ACE5CA7EE69
#define BDEC60EA_9D6B_4DEA_B3DC_4ACE5CA7EE69
#include "../ecs.hpp"
#include "sprite.hpp"
#include "../../constants.hpp"


namespace ze {


    class Tree : public ze::Component {

        private:
            ze::Sprite sprite;

        public:
            Tree();
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* obj) override;

    };
    
} // namespace ze


#endif /* BDEC60EA_9D6B_4DEA_B3DC_4ACE5CA7EE69 */

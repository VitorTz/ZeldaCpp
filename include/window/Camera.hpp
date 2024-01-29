#ifndef BE5465FC_6F23_47C3_B690_1F623FCB007E
#define BE5465FC_6F23_47C3_B690_1F623FCB007E
#include "../ecs/Group.hpp"
#include "../constants.hpp"
#include <algorithm>
#include <vector>

namespace ze {


    class Camera : public ze::Group {

        private:
            static void sortObjByCenterY(std::vector<ze::GameObj*>* v);

        private:
            std::map<int, std::vector<ze::GameObj*>> gameObjByIndex;

        public:
            Camera() : ze::Group(ze::GroupId::CameraGroup) { }
            void draw(sf::RenderWindow& window, const sf::Vector2f offset);
            void add(ze::GameObj* obj) override;
            void erase(ze::GameObj* obj) override;            
            void update([[maybe_unused]] float dt) override { }

    };
    
} // namespace ze


#endif /* BE5465FC_6F23_47C3_B690_1F623FCB007E */

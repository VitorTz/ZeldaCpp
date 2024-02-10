#pragma once
#include <algorithm>
#include <vector>
#include "../ecs/Group.hpp"
#include "../constants.hpp"


namespace ze {


    class Camera : public ze::Group {

        private:
            std::map<int, std::vector<ze::GameObj*>> objMap;
            static void sortObjsByCenterY(std::vector<ze::GameObj*>& v);

        public:
            Camera();
            void insert(ze::GameObj* obj) override;
            void insert(const std::unique_ptr<ze::GameObj>& obj) override;
            void erase(ze::GameObj* obj) override;     
            void clear() override;
            void draw(sf::RenderWindow& window, const sf::Vector2f offset);

    }; 

} // namespace ze


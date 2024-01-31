#ifndef BB158CDF_84EC_4608_B958_6E4E8880B3B7
#define BB158CDF_84EC_4608_B958_6E4E8880B3B7
#include <algorithm>
#include <vector>
#include <map>
#include "../ecs/Group.hpp"
#include "../constants.hpp"


namespace ze {


    class Camera : public ze::Group {

        private:
            std::map<int, std::vector<ze::GameObj*>> objsByIndex;
        
        private:
            static void sortByYpos(std::vector<ze::GameObj*>& v);

        public:
            Camera(Camera&& ) = default;
            Camera();
            void insert(ze::GameObj* gameObj) override;
            void erase(ze::GameObj* gameObj) override;
            void rmvFromCamera(ze::GameObj* gameObj);
            void draw(sf::RenderWindow& window, sf::Vector2f offset);

    };
    
} // namespace ze


#endif /* BB158CDF_84EC_4608_B958_6E4E8880B3B7 */

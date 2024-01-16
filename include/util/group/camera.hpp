#ifndef DF43FC43_D8C5_44AE_BBF2_1246F310F479
#define DF43FC43_D8C5_44AE_BBF2_1246F310F479
#include <memory>
#include <map>
#include <vector>
#include <algorithm>
#include "group.hpp"


namespace ze {


    class Camera : public ze::Group {

        private:
            std::map<ze::Zindex, std::vector<std::shared_ptr<ze::GameObj>>> objs;
        
        private:
            void sortObjVector(std::vector<std::shared_ptr<ze::GameObj>>& v);
            
        public:
            Camera();
            void add(const std::shared_ptr<ze::GameObj>& obj) override;
            void rmv(const std::shared_ptr<ze::GameObj>& obj) override; 
            void update(const float dt) override;
            void draw(sf::RenderWindow& window);
            void draw(sf::RenderWindow& window, const sf::Vector2f& offset);

    };
    
} // namespace ze


#endif /* DF43FC43_D8C5_44AE_BBF2_1246F310F479 */

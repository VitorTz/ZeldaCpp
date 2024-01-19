#ifndef B281D9E7_44D2_4F53_AC77_0F778FC28147
#define B281D9E7_44D2_4F53_AC77_0F778FC28147
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include "../ecs/ecs.hpp"


namespace ze {


    class Camera : public ze::Group {

        private:
            std::map<ze::Zindex, std::vector<ze::GameObj*>> objMap;
        
        private:
            void ySortObjs(std::vector<ze::GameObj*>& v);
        
        public:
            Camera();            
            void draw(sf::RenderWindow& window, const sf::Vector2f& offset);
            void draw(sf::RenderWindow& window);            
            void add(ze::GameObj* obj) override;
            void rmv(ze::GameObj* obj) override;            
            void clear() override;
            
    };
    
} // namespace ze


#endif /* B281D9E7_44D2_4F53_AC77_0F778FC28147 */

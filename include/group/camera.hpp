#ifndef B281D9E7_44D2_4F53_AC77_0F778FC28147
#define B281D9E7_44D2_4F53_AC77_0F778FC28147
#include <map>
#include <vector>
#include <algorithm>
#include "group.hpp"


namespace og {


    class Camera : public og::Group {

        private:
            std::map<og::Zindex, std::vector<og::GameObj*>> objMap;
        
        private:
            void ySortObjs(std::vector<og::GameObj*>& v);
        
        public:
            Camera();            
            void draw(sf::RenderWindow& window, const sf::Vector2f& offset);
            void draw(sf::RenderWindow& window);
            bool contains(og::GameObj* obj) const override;
            void add(og::GameObj* obj) override;
            void rmv(og::GameObj* obj) override;
            
    };
    
} // namespace og


#endif /* B281D9E7_44D2_4F53_AC77_0F778FC28147 */

#ifndef E8F5E3E2_1687_4774_855A_F78869BFE231
#define E8F5E3E2_1687_4774_855A_F78869BFE231
#include "../../ecs/ecs.hpp"
#include <memory>
#include <string>
#include <map>


namespace ze {


    class Group {

        public:
            const std::string name;
        
        public:
            Group(const std::string& name);
            virtual ~Group();
            virtual void add(const std::shared_ptr<ze::GameObj>& obj) = 0;
            virtual void rmv(const std::string& name) = 0;
            virtual void update(const float dt) = 0;
            virtual void draw(sf::RenderWindow& window) = 0;
            virtual ze::GameObj* get(const std::string& name) = 0;
            
    };
    
} // namespace ze


#endif /* E8F5E3E2_1687_4774_855A_F78869BFE231 */

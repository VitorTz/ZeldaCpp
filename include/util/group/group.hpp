#ifndef E8F5E3E2_1687_4774_855A_F78869BFE231
#define E8F5E3E2_1687_4774_855A_F78869BFE231
#include "../../ecs/ecs.hpp"
#include <memory>
#include <string>
#include <set>


namespace ze {


    class Group {

        private:
            std::set<std::shared_ptr<ze::GameObj>> objs;

        public:
            const std::string name;
        
        public:
            Group(const std::string& name);
            virtual ~Group();
            virtual void add(const std::shared_ptr<ze::GameObj>& obj);
            virtual void rmv(const std::shared_ptr<ze::GameObj>& obj);
            virtual bool contains(const std::shared_ptr<ze::GameObj>& obj) const;
            virtual bool collide(const std::shared_ptr<ze::GameObj>& obj) const;
            virtual void update(const float dt);
            virtual std::set<std::shared_ptr<ze::GameObj>>& getObjs();
    };
    
} // namespace ze


#endif /* E8F5E3E2_1687_4774_855A_F78869BFE231 */

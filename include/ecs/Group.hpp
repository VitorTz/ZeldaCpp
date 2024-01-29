#ifndef E96E4985_A138_4A66_9324_454048BC83C8
#define E96E4985_A138_4A66_9324_454048BC83C8
#include "ecs.hpp"
#include <vector>
#include <set>


namespace ze {


    enum GroupId {
        CollideGroup,
        CameraGroup,
        TreesGroup,
        AllGroup
    };


    const std::vector<ze::GroupId> allGroupsIds = {
        CollideGroup,        
        TreesGroup,
        AllGroup
    };
    

    class Group {

        public:
            const ze::GroupId id;

        private:
            std::set<ze::GameObj*> objs;
        
        public:
            Group(const ze::GroupId id) : id(id) { }
            virtual ~Group() = default;
            virtual void add(ze::GameObj* obj) { objs.insert(obj); }
            virtual void erase(ze::GameObj* obj) { objs.erase(obj); }
            virtual void update(float dt) { for (auto* val : objs) val->update(dt); }
            inline std::size_t size() const { return objs.size(); }
            std::set<ze::GameObj*>* getAll() { return &objs; };

    };
    
} // namespace ze


#endif /* E96E4985_A138_4A66_9324_454048BC83C8 */

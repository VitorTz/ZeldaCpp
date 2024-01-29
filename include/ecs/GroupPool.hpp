#ifndef D3B581ED_15A7_4CA5_A052_D8E0B061E568
#define D3B581ED_15A7_4CA5_A052_D8E0B061E568
#include "Group.hpp"


namespace ze {


    class GroupPool {

        private:
            std::map<ze::GroupId, std::unique_ptr<ze::Group>> groupMap;
            std::map<ze::GameObj*, std::set<ze::GroupId>> groupsByGameObj;
        
        public:
            GroupPool() { for (const ze::GroupId id : ze::allGroupsIds) create(id); };
            inline void create(ze::GroupId id) { groupMap.insert({id, std::make_unique<ze::Group>(id)}); }
            inline void create(std::unique_ptr<ze::Group> group) { groupMap.insert({group->id, std::move(group)}); }
            inline ze::Group* get(const ze::GroupId id) { return groupMap.at(id).get(); }
            void addToGroup(ze::GameObj* obj, const ze::GroupId id);
            void addToGroup(ze::GameObj* obj, const std::vector<ze::GroupId>& ids);
            void rmvFromGroup(ze::GameObj* obj, const ze::GroupId id);
            void rmvFromAllGroups(ze::GameObj* obj);
            bool collideGroup(ze::GameObj* obj, ze::GroupId id);

    };
    
} // namespace ze


#endif /* D3B581ED_15A7_4CA5_A052_D8E0B061E568 */

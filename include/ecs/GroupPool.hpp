#ifndef D20CC6E7_E984_4F71_8464_E73E6A011553
#define D20CC6E7_E984_4F71_8464_E73E6A011553
#include "Group.hpp"
#include "../window/Camera.hpp"
#include <map>


namespace ze {


    class GroupPool {

        private:
            std::map<ze::GroupId, std::unique_ptr<ze::Group>> groupMap;
            std::map<ze::GameObj*, std::set<ze::GroupId>> groupsByGameObj;
        
        public:
            GroupPool();
            void addToGroup(ze::GameObj* gameObj, ze::GroupId id);
            void rmvFromGroup(ze::GameObj* gameObj, ze::GroupId id);
            void rmvFromAllGroups(ze::GameObj* gameObj);
            ze::Group* get(ze::GroupId id);

    };
    
} // namespace ze


#endif /* D20CC6E7_E984_4F71_8464_E73E6A011553 */

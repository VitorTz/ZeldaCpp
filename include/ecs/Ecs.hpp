#pragma once
#include "Group.hpp"


namespace ze {


    class Ecs {

        private:
            static std::map<ze::GroupId, std::unique_ptr<ze::Group>> groupMap;
            static std::map<std::string, std::unique_ptr<ze::GameObj>> allObjs;
            static std::map<ze::GameObj*, std::set<ze::GroupId>> groupByGameObj;

        public:
            static void init();
            static void createGroup(ze::GroupId id);
            static void createGroup(std::unique_ptr<ze::Group> group);
            static ze::Group* getGroup(ze::GroupId id);

            static void createGameObj(
                const std::string& name, 
                int zIndex,
                const std::vector<ze::GroupId>& groups
            );

            static ze::GameObj* getGameObj(const std::string& name);

            static void deleteGameObj(ze::GameObj* gameObj);
            static bool collideGroup(ze::GameObj* gameObj, ze::GroupId id);

            static void rmvFromGroup(ze::GameObj* gameObj, ze::GroupId id);
            static void addToGroup(ze::GameObj* gameObj, ze::GroupId id);
        
    };
    
} // namespace ze

#pragma once
#include "Group.hpp"
#include "../window/Camera.hpp"


namespace ze {

    class GroupPool {

        private:
            std::map<ze::GroupId, std::unique_ptr<ze::Group>> groupMap;
            std::map<ze::GameObj*, std::set<ze::GroupId>> groupByGameObj;
        
        public:
            GroupPool();
            void addToGroup(ze::GameObj* gameObj, ze::GroupId id);
            void rmvFromGroup(ze::GameObj* gameObj, ze::GroupId id);            
            void rmvGameObj(ze::GameObj* gameObj);
            ze::Group* at(ze::GroupId id);
            std::set<ze::GroupId>* getGroupsByGameObj(ze::GameObj* gameObj);
            bool collideGroup(ze::GameObj* gameObj, ze::GroupId id);

    };


    class GameObjPool {

        private:
            std::map<std::string, std::unique_ptr<ze::GameObj>> allObjs;
            
        public:
            GameObjPool() = default;
            ze::GameObj* insert(
                const std::string& name,
                int zIndex,
                ze::GroupPool* groupPool,
                const std::vector<ze::GroupId>& groups
            );
            ze::GameObj* at(const std::string& name);
            void erase(ze::GameObj* gameObj, ze::GroupPool* groupPool);
            void erase(const std::string& name, ze::GroupPool* groupPool);
            void update(float dt);
            std::size_t size() const;

    };


    class Ecs {

        public:
            static std::unique_ptr<ze::GroupPool> groupPool;
            static std::unique_ptr<ze::GameObjPool> gameObjPool;

    };



    
} // namespace ze

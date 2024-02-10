#pragma once
#include <set>
#include <vector>
#include "GameObj.hpp"


namespace ze {


    enum GroupId {        
        CollideGroup,
        CameraGroup
    };

    const std::vector<ze::GroupId> groupsIds = {        
        ze::GroupId::CollideGroup,
        ze::GroupId::CameraGroup
    };


    class Group {

        public:
            const ze::GroupId id;
        
        private:
            std::set<ze::GameObj*> objs;
        
        public:
            Group(const ze::GroupId id) : id(id) { }
            virtual ~Group() = default;
            virtual void insert(ze::GameObj* obj) { objs.insert(obj); };
            virtual void insert(const std::unique_ptr<ze::GameObj>& obj) { objs.insert(obj.get()); }
            virtual void erase(ze::GameObj* obj) { objs.erase(obj); };
            virtual void clear() { objs.clear(); };
            virtual std::set<ze::GameObj*>* getAll() { return &objs; }
            virtual void update(const float dt) {
                for (const auto& obj : objs) 
                    obj->update(dt);
            }

    };
    
} // namespace ze

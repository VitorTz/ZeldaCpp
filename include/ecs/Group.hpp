#pragma once
#include <vector>
#include <set>
#include "GameObj.hpp"


namespace ze {


    enum GroupId {        
        CollideGroup,
        CameraGroup
    };

    const std::vector<ze::GroupId> groupsIds = {        
        ze::GroupId::CollideGroup        
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
            virtual void erase(ze::GameObj* obj) { objs.erase(obj); };
            virtual void clear() { objs.clear(); };
            virtual std::set<ze::GameObj*>* getAll() { return &objs; }            
            std::size_t size() const { return objs.size(); }

    };
    
} // namespace ze

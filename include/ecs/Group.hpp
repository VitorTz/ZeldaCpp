#ifndef F0B2E537_6D1C_4FF3_8359_0728FD455559
#define F0B2E537_6D1C_4FF3_8359_0728FD455559
#include "GameObj.hpp"
#include <vector>
#include <set>


namespace ze {


    enum GroupId {
        CameraGroup,
        AllGroup
    };  


    const std::vector<ze::GroupId> allGroups = {
        ze::GroupId::AllGroup
    };


    class Group {

        private:
            std::set<ze::GameObj*> allObjs;

        public:
            const GroupId id;

        public:
            Group(const GroupId id ) : id(id) { }
            virtual ~Group() = default;
            virtual void update(float dt);
            virtual void insert(ze::GameObj* gameObj);
            virtual void erase(ze::GameObj* gameObj);
            bool contains(ze::GameObj* gameObj);
            std::set<ze::GameObj*>* getAllObjs();


    };
    
} // namespace ze


#endif /* F0B2E537_6D1C_4FF3_8359_0728FD455559 */

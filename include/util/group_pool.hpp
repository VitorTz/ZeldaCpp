#ifndef A8ABFDD1_8B79_4E38_8699_56BC5C7212B5
#define A8ABFDD1_8B79_4E38_8699_56BC5C7212B5
#include "../group/group.hpp"
#include "../group/camera.hpp"
#include <memory>
#include <map>
#include <vector>


namespace ze {


    class GroupPool {

        private:
            std::map<std::string, std::unique_ptr<ze::Group>> groupMap;

        public:
            GroupPool();
            void create(const std::string& name);
            void create(std::unique_ptr<ze::Group> group);
            void addObj(ze::GameObj* obj);
            void rmvObj(ze::GameObj* obj);
            void rmvObj(ze::GameObj* obj, const std::vector<std::string>& groups);
            std::unique_ptr<ze::Group>& getGroup(const std::string& groupName);

    };
    
} // namespace ze


#endif /* A8ABFDD1_8B79_4E38_8699_56BC5C7212B5 */

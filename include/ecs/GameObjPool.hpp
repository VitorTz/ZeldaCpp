#ifndef BC92826A_EA0D_4236_9210_510E21353D82
#define BC92826A_EA0D_4236_9210_510E21353D82
#include "GroupPool.hpp"


namespace ze {


    class GameObjPool {

        public:            
            std::unique_ptr<GroupPool> groupPool = std::make_unique<ze::GroupPool>();
            std::map<std::string, std::unique_ptr<ze::GameObj>> objMap;            
            
        public:
            GameObjPool() = default;
            ~GameObjPool();
            void create(
                const std::string& name, 
                int zIndex,
                const std::vector<ze::GroupId>& groups
            );
            void create(
                const std::string& name, 
                int zIndex,
                const std::vector<ze::GroupId>& groups,
                std::unique_ptr<ze::Component> component
            );
            ze::GameObj* get(const std::string& name);
            void erase(const std::string& name);
            void erase(ze::GameObj* gameObj);

    };
    
} // namespace ze


#endif /* BC92826A_EA0D_4236_9210_510E21353D82 */

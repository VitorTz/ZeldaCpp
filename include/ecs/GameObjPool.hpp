#ifndef D8E09C14_5798_4C02_B9D3_9D71BCE1AB42
#define D8E09C14_5798_4C02_B9D3_9D71BCE1AB42
#include "GroupPool.hpp"


namespace ze {


    class GameObjPool {

        private:
            std::map<std::string, std::unique_ptr<ze::GameObj>> gameObjMap;
            ze::GroupPool groupPool;        
        
        public:
            GameObjPool() = default;
            ~GameObjPool();
        
        public:
            void create(
                const std::string& name, 
                ze::Zindex zIndex,
                const std::vector<ze::GroupId>& groups
            );
            void create(
                const std::string& name, 
                ze::Zindex zIndex,
                const std::vector<ze::GroupId>& groups,
                std::unique_ptr<ze::Component> component
            );
            ze::GameObj* get(const std::string& name);
            void erase(const std::string& name);
            void erase(ze::GameObj* gameObj);            
            ze::Group* getGroup(ze::GroupId id);            std::set<ze::GameObj*> getObjsByGroup(ze::GroupId id);


    };
    
} // namespace ze



#endif /* D8E09C14_5798_4C02_B9D3_9D71BCE1AB42 */

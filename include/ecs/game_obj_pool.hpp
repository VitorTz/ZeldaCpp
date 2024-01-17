#ifndef DEC817CB_652C_44D0_B033_D3F2F906DB82
#define DEC817CB_652C_44D0_B033_D3F2F906DB82
#include "ecs.hpp"
#include <map>


namespace og {

    class GameObjPool {

        private:
            std::map<std::string, std::unique_ptr<og::GameObj>> objs;

        public:
            GameObjPool();
            void update(const float dt);
            void add(std::unique_ptr<og::GameObj>& obj);
            void rmv(const std::string& objName);
            std::map<std::string, std::unique_ptr<og::GameObj>>* getObjs();


    };
    
} // namespace og


#endif /* DEC817CB_652C_44D0_B033_D3F2F906DB82 */

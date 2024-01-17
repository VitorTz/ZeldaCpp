#ifndef E93E0E5D_9337_4D8B_B3A0_B5E5B44FFCA0
#define E93E0E5D_9337_4D8B_B3A0_B5E5B44FFCA0
#include <set>
#include "../ecs/ecs.hpp"


namespace og {


    class Group {

        public:
            const std::string name;

        private:
            std::set<og::GameObj*> objs;

        public:
            Group(const std::string& name);
            virtual bool contains(og::GameObj* obj) const;
            virtual void add(og::GameObj* obj);
            virtual void rmv(og::GameObj* obj);
            std::set<og::GameObj*>* getObjs();

    };
    
} // namespace og


#endif /* E93E0E5D_9337_4D8B_B3A0_B5E5B44FFCA0 */

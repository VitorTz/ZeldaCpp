#ifndef ECEF5D01_2A18_4A6C_AFE0_05CBE9E29C5B
#define ECEF5D01_2A18_4A6C_AFE0_05CBE9E29C5B
#include "group.hpp"

namespace ze {

    class GameObjGroup : public ze::Group {

        private:
            std::map<std::string, std::shared_ptr<ze::GameObj>> objs;

        public:
            GameObjGroup(const std::string& name);
            void add(const std::shared_ptr<ze::GameObj>& obj) override;
            void rmv(const std::string& name) override;
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            ze::GameObj* get(const std::string& name) override;
        
    };
    
} // namespace ze


#endif /* ECEF5D01_2A18_4A6C_AFE0_05CBE9E29C5B */

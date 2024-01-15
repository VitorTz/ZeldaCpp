#ifndef E28C1E9F_D8F4_430D_95A2_16A35B80FA71
#define E28C1E9F_D8F4_430D_95A2_16A35B80FA71
#include <filesystem>
#include <algorithm>
#include <vector>
#include <cmath>
#include "sprite.hpp"
#include "../../constants.hpp"


namespace ze {


    class Animation : public ze::Component {

        private:
            std::vector<std::unique_ptr<ze::Sprite>> spriteList;
            std::vector<std::unique_ptr<ze::Sprite>> maskList;
            float spriteIndex;
            bool maskIsEnable;

        public:
            explicit Animation(const std::string& name);
            void reset();
            void enableMask();
            void disableMask();
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;
        
    };

    
} // namespace ze


#endif /* E28C1E9F_D8F4_430D_95A2_16A35B80FA71 */

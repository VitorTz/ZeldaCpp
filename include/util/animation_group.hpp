#ifndef C05D5674_1428_4E14_AC34_A04A03B6248F
#define C05D5674_1428_4E14_AC34_A04A03B6248F
#include <string>
#include <map>
#include "../ecs/components/animation.hpp"


namespace ze {

    class AnimationGroup {

        private:
            const std::string name;
            std::map<std::string, std::unique_ptr<ze::Animation>> animationMap;
            std::string currentAnimation;

        public:
            AnimationGroup(const std::string& name, const std::vector<std::string>& animations);
            explicit AnimationGroup(const std::vector<std::string>& animations);
            void addAnimation(const std::string& name);
            void update(const float  dt);
            void draw(sf::RenderWindow& window);
            void change(const std::string& name);
            void setGameObj(ze::GameObj* gameObj);            
            void enableMask();
            void disableMask();
            const std::string& getName() const;
    };
    
} // namespace ze


#endif /* C05D5674_1428_4E14_AC34_A04A03B6248F */

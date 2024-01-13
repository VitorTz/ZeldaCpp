#ifndef D9B23DF8_581A_4CA3_B19E_9C3EEA780CE8
#define D9B23DF8_581A_4CA3_B19E_9C3EEA780CE8
#include "../ecs.hpp"

namespace ze {

    class Sprite : public ze::Component {
        
        protected:
            ze::ImageSource source;
            sf::Sprite sprite;

        public:
            Sprite(
                const std::string& name,
                const ze::ImageSource& ImageSource
            );            
            ~Sprite() override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;

    };
    
} // namespace ze


#endif /* D9B23DF8_581A_4CA3_B19E_9C3EEA780CE8 */

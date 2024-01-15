#ifndef D9B23DF8_581A_4CA3_B19E_9C3EEA780CE8
#define D9B23DF8_581A_4CA3_B19E_9C3EEA780CE8
#include "../ecs.hpp"
#include "../../util/texture_pool.hpp"


namespace ze {

    class Sprite : public ze::Component {
        
        protected:
            const ze::ImageSource source;
            sf::Sprite sprite;

        public:
            Sprite(
                const std::string& name,
                const ze::ImageSource& imageSource
            );            
            explicit Sprite(const ze::ImageSource& imageSource);
            ~Sprite() override;
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* gameObj) override;
            const ze::ImageSource& getSource() const;

    };
    
} // namespace ze


#endif /* D9B23DF8_581A_4CA3_B19E_9C3EEA780CE8 */

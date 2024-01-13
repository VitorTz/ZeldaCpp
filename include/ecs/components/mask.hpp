#ifndef D0614BFE_0AF3_4354_9707_6A360FCCC753
#define D0614BFE_0AF3_4354_9707_6A360FCCC753
#include "../ecs.hpp"
#include "sprite.hpp"


namespace ze {


    class Mask : public ze::Sprite {

        public:
            Mask(
                const std::string& name,
                const std::string& path,
                const sf::Color& color
            );

    };
    
} // namespace ze


#endif /* D0614BFE_0AF3_4354_9707_6A360FCCC753 */

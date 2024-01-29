#ifndef C2423835_EA79_479E_91AF_EDBA36464A25
#define C2423835_EA79_479E_91AF_EDBA36464A25
#include <filesystem>
#include "../ecs.hpp"
#include "../../util/TexturePool.hpp"


namespace ze {


    class Sprite : public ze::Component {

        private:
            const std::filesystem::path source;
            sf::Sprite sprite;

        public:
            Sprite(
                const std::filesystem::path& source
            ) : ze::Component("Sprite-" + source.string()),
                source(source) { ze::TexturePool::load(&this->sprite, this->source); } 
            ~Sprite() { ze::TexturePool::erase(this->source); };
            void draw(sf::RenderWindow& window) override;
            void setGameObj(ze::GameObj* obj) override;

    };
    
} // namespace ze


#endif /* C2423835_EA79_479E_91AF_EDBA36464A25 */

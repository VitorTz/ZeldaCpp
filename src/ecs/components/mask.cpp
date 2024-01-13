#include "../../../include/ecs/components/mask.hpp"



ze::Mask::Mask(
    const std::string& name,
    const std::string& path,
    const sf::Color& color
) : ze::Sprite(name, {path, true, color}) {
    
}


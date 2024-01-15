#ifndef D335C10F_BB06_4A2B_98BD_AD5B30890223
#define D335C10F_BB06_4A2B_98BD_AD5B30890223
#include <map>
#include <string>


namespace ze {

    enum Direction {
        Left,
        Right,
        Up,
        Down
    };

    const std::map<ze::Direction, std::string> directionToStr = {
        {ze::Direction::Left, "left"},
        {ze::Direction::Right, "right"},
        {ze::Direction::Up, "up"},
        {ze::Direction::Down, "down"}
    };
    
} // namespace ze


#endif /* D335C10F_BB06_4A2B_98BD_AD5B30890223 */

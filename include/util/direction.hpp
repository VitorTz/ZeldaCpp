#ifndef E6495F68_6F2A_4ED4_8830_A43E78CDCB17
#define E6495F68_6F2A_4ED4_8830_A43E78CDCB17
#include <string>
#include <map>


namespace ze {

    enum Direction {
        Left,
        Right,
        Down,
        Up
    };

    const std::map<ze::Direction, std::string> directionToStr = {
        {ze::Direction::Left, "left"},
        {ze::Direction::Right, "right"},
        {ze::Direction::Down, "down"},
        {ze::Direction::Up, "up"}
    };
    
} // namespace ze


#endif /* E6495F68_6F2A_4ED4_8830_A43E78CDCB17 */

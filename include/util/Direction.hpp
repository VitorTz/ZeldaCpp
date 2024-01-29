#ifndef C2F9B7D2_04F5_4937_A30B_8D735286A6C6
#define C2F9B7D2_04F5_4937_A30B_8D735286A6C6
#include <string>


namespace ze {


    enum Direction {
        Left,
        Right,
        Down,
        Up,
        Idle
    };

    const std::map<ze::Direction, std::string> strByDirection = {
        {ze::Direction::Left, "left"},
        {ze::Direction::Right, "right"},
        {ze::Direction::Down, "down"},
        {ze::Direction::Up, "up"},
        {ze::Direction::Idle, "idle"}
    };

    
} // namespace ze


#endif /* C2F9B7D2_04F5_4937_A30B_8D735286A6C6 */

#ifndef CF835648_67A7_4683_9CC3_47333AC95430
#define CF835648_67A7_4683_9CC3_47333AC95430
#include <string>
#include <map>

namespace ze {

    enum GameObjState {
        Moving,
        Idle,
        Attacking,
        Damage
    };

    const std::map<ze::GameObjState, std::string> stateToStr = {
        {ze::GameObjState::Idle, "idle"},
        {ze::GameObjState::Moving, "moving"},
        {ze::GameObjState::Attacking, "attack"},
        {ze::GameObjState::Damage, "damage"}
    };


} // namespace ze


#endif /* CF835648_67A7_4683_9CC3_47333AC95430 */

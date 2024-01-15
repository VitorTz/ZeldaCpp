#ifndef A69ACFCB_8EFB_481E_80AC_BE4409C7051A
#define A69ACFCB_8EFB_481E_80AC_BE4409C7051A
#include <map>
#include <string>


namespace ze {

    enum Action {
        Moving,
        Idle,
        Attack,
        Damage
    };

    const std::map<ze::Action, std::string> actionToStr = {
        {ze::Action::Moving, "moving"},
        {ze::Action::Idle, "idle"},
        {ze::Action::Attack, "attack"},
        {ze::Action::Damage, "moving"}
    };

    
} // namespace ze


#endif /* A69ACFCB_8EFB_481E_80AC_BE4409C7051A */

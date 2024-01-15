#ifndef EA047A8B_2452_49DF_BCF6_227ACDB3176A
#define EA047A8B_2452_49DF_BCF6_227ACDB3176A
#include "action.hpp"
#include "direction.hpp"


namespace ze {

    typedef struct GameObjState {
        ze::Direction direction = ze::Direction::Down;
        ze::Action action = ze::Action::Idle;
        bool isAlive = { true };
        inline std::string toStr(const std::string& preffix = {""}) {
            std::string s = preffix + ze::directionToStr.at(this->direction) + '_' + ze::actionToStr.at(this->action);
            return s;
        }
    } GameObjState;

    
} // namespace ze


#endif /* EA047A8B_2452_49DF_BCF6_227ACDB3176A */

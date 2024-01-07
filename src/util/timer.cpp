#include "../../include/util/timer.hpp"


ze::Timer::Timer(
    const float& timeInSeconds
) : startedTime(ze::globals::currentTime),
    timeInSeconds(timeInSeconds) {

    }



bool ze::Timer::check() {
    const bool status = (ze::globals::currentTime - this->startedTime) >= this->timeInSeconds;
    if (status)
        this->startedTime = ze::globals::currentTime;
    return status;
}
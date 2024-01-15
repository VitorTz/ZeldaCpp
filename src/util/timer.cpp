#include "../../include/util/timer.hpp"



ze::Timer::Timer(
    const float timeInSeconds
) : clock({}),
    startedTime(this->clock.getElapsedTime().asSeconds()),
    timeInSeconds(timeInSeconds) {

}


void ze::Timer::reset() {
    this->startedTime = this->clock.getElapsedTime().asSeconds();
}


bool ze::Timer::check() const {
    return this->clock.getElapsedTime().asSeconds() - this->startedTime >= this->timeInSeconds;
}
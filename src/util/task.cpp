#include "../../include/util/task.hpp"


ze::Task::Task(
    const float timeInSeconds
) : timeInMicroSeconds(timeInSeconds * 1000000),
    t_is_running(false) {

    }


void ze::Task::start(const std::function<void()> f) {
    if (!this->t_is_running) {
        this->t_is_running = true;
        
        this->t = std::thread(
            [this](const std::function<void()>& func) {
                std::this_thread::sleep_for(std::chrono::microseconds(this->timeInMicroSeconds));
                func();
                this->t_is_running = false;
            },
            f
        );        
        t.detach();
    }
}


bool ze::Task::is_running() const {
    return this->t_is_running;
}
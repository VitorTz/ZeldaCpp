#ifndef E303C364_0306_42A4_BEE6_A50EDE228EEC
#define E303C364_0306_42A4_BEE6_A50EDE228EEC
#include <SFML/System/Clock.hpp>
#include <functional>
#include <thread>
#include <chrono>


namespace ze {

    class Task {

        private:
            const u_int64_t timeInMicroSeconds;            
            bool t_is_running;
            std::thread t;

        public:            
            Task(const float timeInSeconds);
            void start(const std::function<void()> f);
            bool is_running() const;

    };
    
} // namespace ze


#endif /* E303C364_0306_42A4_BEE6_A50EDE228EEC */

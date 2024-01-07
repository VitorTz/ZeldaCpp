#pragma once
#include "../globals.hpp"




namespace ze {

    class Timer {

        private:
            float startedTime;
            const float timeInSeconds;
        
        public:
            Timer(const float& timeInSeconds);
            bool check();

    };
    
} // namespace ze

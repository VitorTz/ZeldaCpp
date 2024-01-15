#ifndef C4AB2352_F093_4503_A917_B63AD82B4835
#define C4AB2352_F093_4503_A917_B63AD82B4835
#include <SFML/System/Clock.hpp>



namespace ze {

    class Timer {

        private:
            sf::Clock clock;
            float startedTime;
            float timeInSeconds;
        
        public:
            explicit Timer(float timeInSeconds);
            void reset();
            bool check() const;

    };
    
} // namespace ze


#endif /* C4AB2352_F093_4503_A917_B63AD82B4835 */

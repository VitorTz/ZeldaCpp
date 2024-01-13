#ifndef B198A82C_075E_42BB_BAFA_B2E90F322E82
#define B198A82C_075E_42BB_BAFA_B2E90F322E82
#include "../scene/scenes.hpp"


namespace ze {

    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::unique_ptr<ze::Scene> scene;
            ze::ChangeScene changeScene;

        private:
            void handleInput();
            void update();
            void draw();
        
        public:
            Window();
            void run();

    };
    
} // namespace ze


#endif /* B198A82C_075E_42BB_BAFA_B2E90F322E82 */

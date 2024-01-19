#ifndef DFEEE5BE_E422_4817_98DD_76B35DB694A1
#define DFEEE5BE_E422_4817_98DD_76B35DB694A1
#include <SFML/Graphics.hpp>
#include <functional>
#include "../ecs/ecs.hpp"
#include "../util/camera.hpp"
#include "../util/debug.hpp"


namespace ze {

    enum SceneId {
        LevelId
    };
    
    const ze::SceneId mainScene = ze::SceneId::LevelId;

    typedef std::function<void(const ze::SceneId)> ChangeScene;

    class Scene {
        
        public:
            const ze::SceneId id;
            
        protected:
            const ze::ChangeScene& changeScene;
            std::unique_ptr<ze::GameObjPool> gameObjPool;            

        public:
            Scene(
                const ze::SceneId id, 
                const ze::ChangeScene& changeScene
            );
            virtual ~Scene();
            virtual void update(const float dt);
            virtual void draw(sf::RenderWindow& window);

    };
    
} // namespace ze


#endif /* DFEEE5BE_E422_4817_98DD_76B35DB694A1 */

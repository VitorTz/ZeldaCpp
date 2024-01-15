#ifndef DF43FC43_D8C5_44AE_BBF2_1246F310F479
#define DF43FC43_D8C5_44AE_BBF2_1246F310F479
#include <memory>
#include <vector>
#include <map>
#include "group.hpp"


namespace ze {


    class Camera : public ze::Group {

        private:
            std::map<ze::Zindex, std::map<std::string, std::shared_ptr<ze::GameObj>>> objs;
            std::shared_ptr<ze::GameObj> offsetObj;

        public:
            Camera();
            void update(const float dt) override;
            void draw(sf::RenderWindow& window) override;            
            void add(const std::shared_ptr<ze::GameObj>& obj) override;
            void rmv(const std::string& name) override;
            void rmv(const std::string& name, const ze::Zindex index);
            ze::GameObj* get(const std::string& name) override;
            ze::GameObj* get(const std::string& name, const ze::Zindex zIndex);
            void setOffset(const std::shared_ptr<ze::GameObj>& obj);

    };
    
} // namespace ze


#endif /* DF43FC43_D8C5_44AE_BBF2_1246F310F479 */

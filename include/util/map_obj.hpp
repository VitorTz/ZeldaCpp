#ifndef E495220C_CB01_4CA4_8F35_79CD179C3F85
#define E495220C_CB01_4CA4_8F35_79CD179C3F85
#include <SFML/System/Vector2.hpp>
#include <filesystem>
#include <map>
#include "z_index.hpp"

namespace ze {

    typedef struct MapObj {
        const std::filesystem::path imagePath;
        const std::string name;
        const sf::Vector2f boxColliderScale;
        const ze::Zindex zIndex;
        const std::vector<std::string> groups;
    } MapObj;


    enum MapObjId {
        Ground,
        Tree1,
        Tree2,
        Tree3,
        Tree4
    };

    const std::map<ze::MapObjId, ze::MapObj> mapObjById = {
        {
            ze::MapObjId::Ground, 
            {
                "res/graphics/tilemap/ground.png", 
                "Ground", 
                {1.f, 1.f}, 
                ze::Zindex::GroundIndex,
                {"camera"}
            }
        },
        {
            ze::MapObjId::Tree1, 
            {
                "res/graphics/objects/02.png", 
                "GreenTree1", 
                {0.6, 0.3}, 
                ze::Zindex::PlayerIndex,
                {"camera", "collide", "trees"}
            }
        }, 
        {
            ze::MapObjId::Tree2, 
            {
                "res/graphics/objects/03.png", 
                "GreenTree2", 
                {0.6, 0.3}, 
                ze::Zindex::PlayerIndex,
                {"camera", "collide", "trees"}
            }
        }, 
        {
            ze::MapObjId::Tree3, 
            {
                "res/graphics/objects/04.png", 
                "GreenTree3", 
                {0.6, 0.3}, 
                ze::Zindex::PlayerIndex,
                {"camera", "collide", "trees"}
            }
        }, 
        {
            ze::MapObjId::Tree4, 
            {
                "res/graphics/objects/05.png", 
                "GreenTree4", 
                {0.6, 0.3}, 
                ze::Zindex::PlayerIndex,
                {"camera", "collide", "trees"}
            }
        }

    };

    
} // namespace ze

#endif /* E495220C_CB01_4CA4_8F35_79CD179C3F85 */

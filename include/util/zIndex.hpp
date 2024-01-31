#ifndef A83DE165_24B9_4D9A_A270_20B1E0BC5B0B
#define A83DE165_24B9_4D9A_A270_20B1E0BC5B0B
#include <vector>



namespace ze {

    enum Zindex {

        GroundIndex,
        FornitureIndex,
        PlayerIndex
    };

    const std::vector<ze::Zindex> allZindex = {
        ze::Zindex::GroundIndex,
        ze::Zindex::FornitureIndex,
        ze::Zindex::PlayerIndex
    };
    

    
} // namespace ze



#endif /* A83DE165_24B9_4D9A_A270_20B1E0BC5B0B */

#ifndef C484AD60_74CB_495F_B05C_F99D319146D6
#define C484AD60_74CB_495F_B05C_F99D319146D6
#include <vector>

namespace ze {

    enum Zindex {
        GroundIndex,
        PlayerIndex
    };

    const std::vector<ze::Zindex> zIndexVector = {
        ze::Zindex::GroundIndex,
        ze::Zindex::PlayerIndex
    };
    
} // namespace ze


#endif /* C484AD60_74CB_495F_B05C_F99D319146D6 */

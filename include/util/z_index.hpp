#ifndef C484AD60_74CB_495F_B05C_F99D319146D6
#define C484AD60_74CB_495F_B05C_F99D319146D6
#include <vector>

namespace og {

    enum Zindex {
        GroundIndex,
        PlayerIndex
    };

    const std::vector<og::Zindex> zIndexVector = {
        og::Zindex::GroundIndex,
        og::Zindex::PlayerIndex
    };
    
} // namespace og


#endif /* C484AD60_74CB_495F_B05C_F99D319146D6 */

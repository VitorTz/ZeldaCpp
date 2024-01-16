#ifndef FC2B6C5F_3B31_460D_9A34_314D564D547B
#define FC2B6C5F_3B31_460D_9A34_314D564D547B
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <filesystem>
#include <string>
#include <map>
#include <vector>


namespace ze {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const sf::Vector2f SCREEN_SIZE(SCREEN_WIDTH, SCREEN_HEIGHT);
    const sf::Vector2f SCREEN_CENTER(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    const std::string SCREEN_TITLE = "Zelda";
    const int FPS = 60;
    const int TILE_SIZE = 64;

    // animation
    const float ANIMATION_SPEED = 6;
    const std::map<std::string, std::filesystem::path> animationPathByName = {
        {"player_left_moving", {"res/graphics/player/left_moving"}},
        {"player_left_idle", {"res/graphics/player/left_idle"}},
        {"player_left_attack", {"res/graphics/player/left_attack"}},
        {"player_right_moving", {"res/graphics/player/right_moving"}},
        {"player_right_idle", {"res/graphics/player/right_idle"}},
        {"player_right_attack", {"res/graphics/player/right_attack"}},
        {"player_down_moving", {"res/graphics/player/down_moving"}},
        {"player_down_idle", {"res/graphics/player/down_idle"}},
        {"player_down_attack", {"res/graphics/player/down_attack"}},
        {"player_up_moving", {"res/graphics/player/up_moving"}},
        {"player_up_idle", {"res/graphics/player/up_idle"}},
        {"player_up_attack", {"res/graphics/player/up_attack"}}
    };

    const std::vector<std::string> PLAYER_ANIMATIONS = {
        "player_left_moving",
        "player_left_idle",
        "player_left_attack",
        "player_right_moving",
        "player_right_idle",
        "player_right_attack",
        "player_down_moving",
        "player_down_idle",
        "player_down_attack",
        "player_up_moving",
        "player_up_idle",
        "player_up_attack"
    };

    // res
    const std::filesystem::path GROUND_IMAGE_FILE("res/graphics/tilemap/ground.png");
    const std::filesystem::path TREE_IMAGE_FILE("res/graphics/objects/07.png");
    // player
    const float PLAYER_SPEED = 300.f;
    const float PLAYER_LIFE_POINTS = 150;
    const float PLAYER_ATTACK_TIME = 0.3;
    const float PLAYER_DAMAGE_TIME = 0.5;
    const float PLAYER_ATTACK_SPEED = 0.5;
    const sf::Keyboard::Key ATTACK_KEY = sf::Keyboard::Space;

} // namespace ze


#endif /* FC2B6C5F_3B31_460D_9A34_314D564D547B */

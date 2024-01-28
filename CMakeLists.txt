cmake_minimum_required(VERSION 3.27)
project(ZeldaCpp)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS graphics audio)

add_executable(ZeldaCpp src/main.cpp
        include/Constants.h
        include/window/Window.h
        src/window/Window.cpp
        include/scene/Scene.h
        include/scene/Level.h
        src/scene/Level.cpp
        include/scene/scenes.h
        include/ecs/ecs.h
        src/ecs/GameObj.cpp
        include/ecs/components.h
        src/ecs/Group.cpp
        src/ecs/GroupPool.cpp
        src/ecs/GameObjPool.cpp
        include/window/Camera.h
        include/window/Camera.h
        include/window/Camera.h
        src/window/Camera.cpp
        include/util/Rect.h
        include/util/util.h
        src/util/util.cpp
        src/util/Rect.cpp
        include/ecs/components/Sprite.h
        include/util/TexturePool.h
        src/util/TexurePool.cpp
        src/ecs/components/Sprite.cpp
)

target_link_libraries(ZeldaCpp sfml-graphics sfml-audio)

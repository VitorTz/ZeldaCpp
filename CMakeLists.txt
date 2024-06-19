# CMakeList.txt : Generic CMake project for Raylib (C++), include source and define
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ZeldaCpp" VERSION 1.0 DESCRIPTION "ZeldaCpp")

add_subdirectory(./lib/raylib)

# Add source to this project's executable.

# file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
# file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.h")

# add_executable(${PROJECT_NAME} ${sources} ${headers})

add_executable (${PROJECT_NAME} "src/main.cpp" "src/constants.h" "src/entity_manager.h" "src/types.h" "src/entity_manager.cpp" "src/component_array.h" "src/component_manager.h" "src/components.h"  "src/system.h" "src/system_manager.h" "src/ecs.h" "src/component_type.h" "src/system_transform.cpp" "src/util.h" "src/util.cpp" "src/system_sprite.cpp" "src/scene.h" "src/scene_manager.cpp" "src/scene_title_screen.cpp" "src/texture_pool.h" "src/texture_pool.cpp" "src/system_controller.cpp" "src/scene_level.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# TODO: Add tests and install targets if needed.
target_link_libraries(${PROJECT_NAME} raylib)

# Setting ASSETS_PATH
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
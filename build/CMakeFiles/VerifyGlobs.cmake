# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.25
cmake_policy(SET CMP0009 NEW)

# sources at CMakeLists.txt:16 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/mnt/HD/Programs/vitor/ZeldaCpp/src/*.cpp")
set(OLD_GLOB
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/globals.cpp"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/main.cpp"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/scene_level.cpp"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/scene_title_screen.cpp"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/texture_pool.cpp"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/util.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/mnt/HD/Programs/vitor/ZeldaCpp/build/CMakeFiles/cmake.verify_globs")
endif()

# headers at CMakeLists.txt:17 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/mnt/HD/Programs/vitor/ZeldaCpp/src/*.h")
set(OLD_GLOB
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/constants.h"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/globals.h"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/scene.h"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/sprite.h"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/texture_pool.h"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/types.h"
  "/mnt/HD/Programs/vitor/ZeldaCpp/src/util.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/mnt/HD/Programs/vitor/ZeldaCpp/build/CMakeFiles/cmake.verify_globs")
endif()

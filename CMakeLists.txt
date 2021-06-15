set(SFML_DIR "/home/hohoho/Desktop/programowanko/C++/Libraries/SFML-2.5.1/lib/cmake/SFML")
cmake_minimum_required(VERSION 3.19)
project(tic-tac-toe_SFML)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/stlenyk/CLionProjects/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/stlenyk/CLionProjects/SFML-2.5.1/lib")
set(SFML_DIR "/home/stlenyk/CLionProjects/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if (SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif ()

add_executable(tic-tac-toe_SFML src/main.cpp src/State.cpp src/State.h src/StateMachine.cpp src/StateMachine.h src/Constants.h src/AssetManager.cpp src/AssetManager.h src/InputManager.cpp src/InputManager.h src/GameLoop.cpp src/GameLoop.h src/States/SplashState.cpp src/States/SplashState.h src/States/GameState.cpp src/States/GameState.h)
target_link_libraries(tic-tac-toe_SFML sfml-graphics sfml-window sfml-system)
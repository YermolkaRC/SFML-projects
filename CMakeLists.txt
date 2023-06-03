cmake_minimum_required(VERSION 3.17)
project(sfml-project)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5.1 COMPONENTS graphics window audio system REQUIRED)

add_executable(sfml-project 
"src/logger.hpp" "src/logger.cpp"
"src/main.cpp" 
"src/game.cpp" "src/game.hpp" 
"src/content_manager.hpp" "src/content_manager.cpp"
"src/ui_controls.hpp" "src/ui_controls.cpp"
)

target_link_libraries(sfml-project sfml-graphics sfml-window sfml-audio sfml-system)

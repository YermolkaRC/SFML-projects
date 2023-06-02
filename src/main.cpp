#include <iostream>
#include "game.hpp"

int main() {
    Game g;
    g.Init();
    std::cout << "Initialization complete!\n";
    g.Run();
    std::cout << "Exiting...";

    return 0;
}
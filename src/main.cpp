//
//  main.cpp
//  test_ping_pong
//
//  Created by mcbk on 25.10.2023.
//

#include <iostream>

// #include "glob_var.h"
#include <vector>

#include "game.hpp"

using namespace test_sp;
int main(int argc, const char* argv[]) {
    if (argc > 1) {
        Game g(argv[1]);
        g.PlayGame();
    } else {
        std::cout << "please enter path to cfg.";
    }
    return 0;
}

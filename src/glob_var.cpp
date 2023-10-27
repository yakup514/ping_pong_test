//
//  glob_var.cpp
//  test_ping_pong
//
//  Created by mcbk on 26.10.2023.
//

#include "glob_var.hpp"

#include <stdio.h>
std::atomic<bool> g_game_over{false};
std::mutex g_lockturn;
std::atomic<int> g_team_turn{1};

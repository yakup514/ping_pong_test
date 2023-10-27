//
//  glob_var.h
//  test_ping_pong
//
//  Created by mcbk on 26.10.2023.
//

#ifndef glob_var_h
#define glob_var_h
#include <thread>
extern std::atomic<bool> g_game_over;
extern std::atomic<int> g_team_turn;
extern std::mutex g_lockturn;
#endif /* glob_var_h */

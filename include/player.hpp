//
//  player.hpp
//  test_ping_pong
//
//  Created by mcbk on 26.10.2023.
//

#ifndef player_hpp
#define player_hpp
#include <stdio.h>

#include <iostream>
#include <thread>

#include "glob_var.hpp"

namespace test_sp {
class Player {
    int team_;
    int numb_;
    int team_size_;

   public:
    Player(int team, int numb, int team_size)
        : team_{team}, numb_{numb}, team_size_{team_size} {};
    void Play();
};
}  // namespace test_sp
#endif /* player_hpp */

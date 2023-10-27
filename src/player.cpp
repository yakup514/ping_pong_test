//
//  player.cpp
//  test_ping_pong
//
//  Created by mcbk on 26.10.2023.
//

#include "player.hpp"
namespace test_sp {
void Player::Play() {
    while (1) {
        if (g_game_over.load()) break;
        {
            std::lock_guard<std::mutex> lock(g_lockturn);
            if (team_ == g_team_turn.load()) {
                std::cout << numb_ << '/' << team_size_ << ", ";
                std::cout << team_ << ": ";
                team_ == 1 ? std::cout << "ping" : std::cout << "pong";
                std::cout << '\n';
                g_team_turn.store(g_team_turn.load() == 1 ? 2 : 1);
            }
        }
    }
}
}  // namespace test_sp

#ifndef game_hpp
#define game_hpp
#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"
#include "player.hpp"
namespace test_sp {
class Game {
    std::vector<std::thread> th_;
    int team_size_ = -1;
    std::string path_;
    void InitTeam(int team_size);

   public:
    Game(std::string path) : path_{path} {};
    void PlayGame();
};
}  // namespace test_sp
#endif
#include "game.hpp"
namespace test_sp {
void Game::PlayGame() {
    while (1) {
        if (g_game_over.load()) break;
        try {
            std::ifstream f(path_);
            nlohmann::json data = nlohmann::json::parse(f);
            g_game_over.store(data["game_over"]);
            if (!g_game_over.load() && data["team_size"] >= 0 &&
                data["team_size"] != team_size_) {
                team_size_ = data["team_size"];
                g_game_over.store(true);
                for (auto& t : th_) t.join();
                th_.clear();
                g_game_over.store(false);
                InitTeam(team_size_);
            }
        } catch (...) {
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    for (auto& t : th_) {
        t.join();
    }
}

void Game::InitTeam(int team_size) {
    for (int i = 1; i <= team_size; ++i) {
        Player p1(1, i, team_size), p2(2, i, team_size);
        std::thread t1(&Player::Play, p1);
        std::thread t2(&Player::Play, p2);
        th_.push_back(std::move(t1));
        th_.push_back(std::move(t2));
    }
}

}  // namespace test_sp
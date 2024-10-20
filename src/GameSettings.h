//
// Created by guilherme on 17/10/24.
//

#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
struct GameSettings {
    static constexpr int WINDOW_WIDTH = 640;
    static constexpr int WINDOW_HEIGHT = 640;
    static constexpr int TILE_SIZE = std::min(WINDOW_WIDTH,WINDOW_HEIGHT) / 8;
};
#endif //GAMESETTINGS_H

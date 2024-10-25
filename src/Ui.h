//
// Created by guilherme on 18/10/24.
//

#ifndef UI_H
#define UI_H
#include <vector>

#include "GameSettings.h"
#include "movement/PossibleMove.h"
#include "renderer/Renderer.h"

class Ui {
    public:
    void piecePossiblePositions(std::vector<std::shared_ptr<PossibleMove>> &positions) {
        for (const std::shared_ptr<PossibleMove> &position : positions) {
            SDL_Rect rect;
            rect.x = GameSettings::TILE_SIZE * position->col;
            rect.y = GameSettings::TILE_SIZE * position->row;
            rect.w = GameSettings::TILE_SIZE;
            rect.h = GameSettings::TILE_SIZE;
            SDL_SetRenderDrawColor(Renderer::renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(Renderer::renderer, &rect);
        }
        Renderer::render();
    };
};
#endif //UI_H

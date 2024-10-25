//
// Created by guilherme on 16/10/24.
//

#ifndef PIECE_H
#define PIECE_H
#include <memory>
#include <SDL_render.h>

#include "../movement/MovimentRule.h"


class Piece {
public:
    bool isBlack;
    MovimentRule* movementRule;
    SDL_Rect* pieceRect;
    SDL_Texture* texture;
    int* tile_size;
    bool isFirstMove = true;
    Piece();

    Piece(int row, int col, SDL_Texture* texture, bool isBlack, MovimentRule* movementRule) : movementRule(movementRule),isBlack(isBlack), texture(texture),row(row), col(col) {};
    virtual ~Piece() {
        delete pieceRect;
        delete tile_size;
        delete movementRule;
    }
    virtual void move(int col, int row) {
        pieceRect->y = row * GameSettings::TILE_SIZE;
        pieceRect->x = col * GameSettings::TILE_SIZE;
        this->col = col;
        this->row = row;
        this->isFirstMove = false;
    };
    int row;
    int col;
    void initRect() {
        pieceRect = new SDL_Rect();
        this->pieceRect->x = GameSettings::TILE_SIZE * col;
        this->pieceRect->y = GameSettings::TILE_SIZE * row;
        this->pieceRect->w = GameSettings::TILE_SIZE;
        this->pieceRect->h = GameSettings::TILE_SIZE;
    };
};

#endif //PIECE_H

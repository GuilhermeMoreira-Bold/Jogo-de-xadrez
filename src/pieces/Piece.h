//
// Created by guilherme on 16/10/24.
//

#ifndef PIECE_H
#define PIECE_H
#include <memory>
#include <SDL_render.h>

class Piece {
public:
    bool isBlack;
    SDL_Rect* pieceRect;
    SDL_Texture* texture;
    Piece();
    Piece(int row, int col, SDL_Texture* texture, bool isBlack) : isBlack(isBlack),texture(texture), row(row), col(col) {

    };
    virtual ~Piece() {
        delete pieceRect;
    }
    virtual void move(int posX, int posY) = 0;
    int row;
    int col;
    void initRect() {
        pieceRect = new SDL_Rect();
        this->pieceRect->x = 80 * (col - 1);
        this->pieceRect->y = 80 * (row - 1);
        this->pieceRect->w = 80;
        this->pieceRect->h = 80;
    };
};

#endif //PIECE_H

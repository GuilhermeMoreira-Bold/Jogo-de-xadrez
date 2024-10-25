//
// Created by guilherme on 16/10/24.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
    public:
    Knight(int row, int col, SDL_Texture* texture,bool isBlack,MovimentRule* movementRule) : Piece(row, col, texture, isBlack,movementRule){
        this->texture = texture;
        this->col = col;
        this->row = row;
        this->isBlack = isBlack;
        this->initRect();
    }
};


#endif //KNIGHT_H

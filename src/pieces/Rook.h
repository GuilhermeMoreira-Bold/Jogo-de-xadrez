//
// Created by guilherme on 16/10/24.
//

#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece {
  public:
  Rook(int row, int col, SDL_Texture* texture,bool isBlack,MovimentRule* movementRule) : Piece(row, col, texture, isBlack,movementRule){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
};


#endif //ROOK_H

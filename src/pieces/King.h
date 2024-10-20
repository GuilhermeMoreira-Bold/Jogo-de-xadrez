//
// Created by guilherme on 16/10/24.
//

#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece {
  public:
  King(int row, int col, SDL_Texture* texture,bool isBlack,MovementRule* movementRule) : Piece(row, col, texture, isBlack,movementRule){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
  void move(int col, int row) override {

  }
};
#endif //KING_H

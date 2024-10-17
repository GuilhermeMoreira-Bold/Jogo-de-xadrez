//
// Created by guilherme on 16/10/24.
//

#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece {
  public:
  Rook(int row, int col, SDL_Texture* texture,bool isBlack) : Piece(row, col, texture, isBlack){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
  void move(int posX, int posY) override {

  }
};


#endif //ROOK_H

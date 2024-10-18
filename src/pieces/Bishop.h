//
// Created by guilherme on 16/10/24.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
  public:
  Bishop(int row, int col, SDL_Texture* texture,bool isBlack) : Piece(row, col, texture, isBlack){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
  void move() override {

  }
};
#endif //BISHOP_H

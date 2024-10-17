//
// Created by guilherme on 16/10/24.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece {
  public:
  Pawn(int row, int col, SDL_Texture* texture,bool isBlack) : Piece(row, col, texture, isBlack){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
  void move(int posX, int posY) override {

  }

};
#endif //PAWN_H

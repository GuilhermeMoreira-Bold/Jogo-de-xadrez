//
// Created by guilherme on 16/10/24.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "../renderer/Renderer.h"

class Pawn : public Piece {
  public:
  Pawn(int row, int col, SDL_Texture* texture,bool isBlack) : Piece(row, col, texture, isBlack){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
  void move() override {
    if(isBlack) {
      row += 1;
    }else {
      row -= 1;
    }
    pieceRect->y = row * GameSettings::TILE_SIZE;
  }

};
#endif //PAWN_H

//
// Created by guilherme on 16/10/24.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
  public:
  Bishop(int row, int col, SDL_Texture* texture,bool isBlack,MovimentRule* movementRule) : Piece(row, col, texture, isBlack,movementRule){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
  void move(int col, int row) override {
    pieceRect->y = row * GameSettings::TILE_SIZE;
    pieceRect->x = col * GameSettings::TILE_SIZE;
    this->col = col;
    this->row = row;
    this->isFirstMove = false;
  }
};
#endif //BISHOP_H

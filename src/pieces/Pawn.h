//
// Created by guilherme on 16/10/24.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "../movement/PawnMovimentRule.h"


class Pawn : public Piece{
  public:
  Pawn(int row, int col, SDL_Texture* texture,bool isBlack, MovementRule* movementRule) : Piece(row, col, texture, isBlack,movementRule) {
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
    this->movementRule = movementRule;
  }

  void move(int col, int row) override {
    pieceRect->y = row * GameSettings::TILE_SIZE;
    pieceRect->x = col * GameSettings::TILE_SIZE;
    this->col = col;
    this->row = row;
  }

};
#endif //PAWN_H

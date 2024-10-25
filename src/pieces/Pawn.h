//
// Created by guilherme on 16/10/24.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "../movement/PawnMovimentRule.h"


class Pawn : public Piece{
  public:
  Pawn(int row, int col, SDL_Texture* texture,bool isBlack, MovimentRule* movementRule) : Piece(row, col, texture, isBlack,movementRule) {
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
    this->movementRule = movementRule;
  }

};
#endif //PAWN_H

//
// Created by guilherme on 16/10/24.
//

#ifndef QUEEN_H
#define QUEEN_H


class Queen : public Piece {
    public:
    Queen(int row, int col, SDL_Texture* texture,bool isBlack,MovimentRule* movementRule) : Piece(row, col, texture, isBlack,movementRule){
    this->texture = texture;
    this->col = col;
    this->row = row;
    this->isBlack = isBlack;
    this->initRect();
  }
};

#endif //QUEEN_H

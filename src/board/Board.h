//
// Created by guilherme on 17/10/24.
//

#ifndef SQUARE_H
#define SQUARE_H
#include <memory>
#include "../pieces/Piece.h"

template<typename T>
using Ref = std::shared_ptr<T>;

struct Board {
     Ref<Piece> positions[8][8];
     explicit Board(Ref<Piece> pieces[32]) {
          for (int i = 0; i < 32; i++) {
               positions[pieces[i]->row][pieces[i]->col] = pieces[i];
          };
     };
     void changePiecePosition(int oldRow, int oldCol, Ref<Piece> piece) {
          positions[oldRow][oldCol] = nullptr;
          positions[piece->row][piece->col] = piece;
     }
};
#endif //SQUARE_H

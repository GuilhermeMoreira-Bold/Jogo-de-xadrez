//
// Created by guilherme on 18/10/24.
//

#ifndef PAWNMOVIMENTRULE_H
#define PAWNMOVIMENTRULE_H
//
// Created by guilherme on 17/10/24.
//


#include <vector>
#include "MovementRule.h"
#include "../board/Board.h"
template <typename T>
using Ref = std::shared_ptr<T>;

class PawnMovimentRule : public MovementRule {
public:
    PawnMovimentRule(){};
    bool isFirstMove = true;
    std::vector<Ref<PossibleMoves>> moves = {};
    Ref<Piece> clickedPiece;
    std::vector<Ref<PossibleMoves>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) override {
        clickedPiece = piece;
        moves.clear();
        int direction = piece->isBlack ? 1 : -1;

        if(board->positions[piece->row + direction][piece->col] == nullptr) {
            moves.push_back(std::make_shared<PossibleMoves>(piece->row + 1 * direction, piece->col));
        }
        if (board->positions[piece->row + 2 * direction][piece->col] == nullptr && isFirstMove) {
            moves.push_back(std::make_shared<PossibleMoves>(piece->row + 2 * direction, piece->col));
        }
        isFirstMove = false;
        return moves;
    };
};


#endif //PAWNMOVEMENTRULE_H

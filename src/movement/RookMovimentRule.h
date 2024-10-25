//
// Created by guilherme on 24/10/24.
//

#ifndef ROOKMOVEMENTRULE_H
#define ROOKMOVEMENTRULE_H
#include <vector>

#include "Directions.h"
#include "MovimentRule.h"
#include "../board/Board.h"
#include "../pieces/Piece.h"

class RookMovimentRule : public MovimentRule {
public:
    std::vector<Ref<PossibleMove>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) override {
        std::vector<Ref<PossibleMove>> moves;
        Directions frontDirection(1,0);
        Directions backDirection(-1,0);
        Directions rightSideDirection(0,1);
        Directions leftSideDirection(0,-1);

        std::vector possibleMoves = {frontDirection, backDirection, rightSideDirection, leftSideDirection};

        for (const auto& possibleMove : possibleMoves) {
            int row = piece->row;
            int col = piece->col;

            while (true) {
                row += possibleMove.row;
                col +=  possibleMove.col;

                if (row < 0 || row > 7 || col < 0 || col > 7) break;

                auto target = board->positions[row][col];
                if (target == nullptr) {
                    moves.push_back(std::make_shared<PossibleMove>(row, col));
                }else if (target->isBlack != piece->isBlack) {
                    moves.push_back(std::make_shared<PossibleMove>(row, col));
                    break;
                }else {
                    break;
                }

            }
        }
        return moves;
    }
};

#endif //ROOKMOVEMENTRULE_H

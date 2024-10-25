//
// Created by guilherme on 24/10/24.
//

#ifndef KNIGHTMOVEMENTERULE_H
#define KNIGHTMOVEMENTERULE_H
#include <vector>

#include "Directions.h"
#include "MovimentRule.h"
#include "../board/Board.h"
#include "../pieces/Piece.h"

class KnightMovimenteRule :public MovimentRule {
    std::vector<Ref<PossibleMove>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) override {
        std::vector<Ref<PossibleMove>> moves;
        Directions right1(-2,1);
        Directions right2(-1,2);

        Directions right3(1,2);
        Directions right4(2,1);

        Directions left1(-2,-1);
        Directions left2(-1,-2);

        Directions left3(1,-2);
        Directions left4(2,-1);

        std::vector directions = {right1, right2, right3, right4,left1, left2,left3, left4};

        for (const auto& direction: directions) {
            int row = piece->row + direction.row;
            int col = piece->col + direction.col;

            if (row < 0 || row > 7 || col < 0 || col > 7) continue;

            auto target = board->positions[row][col];

            if (target == nullptr){
                moves.push_back(std::make_shared<PossibleMove>(row, col));
            } else if (target->isBlack != piece->isBlack) {
                moves.push_back(std::make_shared<PossibleMove>(row, col));
            }
        }


        return moves;
    }
};
#endif //KNIGHTMOVEMENTERULE_H

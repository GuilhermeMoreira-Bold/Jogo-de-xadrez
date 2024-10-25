//
// Created by guilherme on 22/10/24.
//

#ifndef BISHOPMOVEMENTRULE_H
#define BISHOPMOVEMENTRULE_H
#include <iostream>
#include <memory>
#include <vector>

#include "Directions.h"
#include "MovimentRule.h"


template <typename T>
using Ref = std::shared_ptr<T>;

class BishopMovementRule :public MovimentRule {
    public:
    BishopMovementRule(){};
    std::vector<Ref<PossibleMove>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) override {
        std::vector<Ref<PossibleMove>> moves;
        Directions topRightDiagonal(1, 1);
        Directions topLeftDiagonal (1,-1);
        Directions bottomRightDiagonal(-1,1);
        Directions bottomLeftDiagonal(-1,-1);
        std::vector directions = {topRightDiagonal, topLeftDiagonal, bottomRightDiagonal, bottomLeftDiagonal};
        moves.clear();

        for (const auto& direction : directions) {
            int row = piece->row;
            int col = piece->col;

            while (true) {
                row += direction.row;
                col += direction.col;

                if (row < 0 || row > 7 || col < 0 || col > 7) break;

                auto target = board->positions[row][col];

                if (target == nullptr){
                    moves.push_back(std::make_shared<PossibleMove>(row, col));
            } else if (target->isBlack != piece->isBlack) {
                    moves.push_back(std::make_shared<PossibleMove>(row, col));
                    break;
                }else {
                    break;
                };
            }
        }

        return moves;
    }
};



#endif //BISHOPMOVEMENTRULE_H

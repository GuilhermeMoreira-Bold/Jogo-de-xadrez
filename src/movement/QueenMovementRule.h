//
// Created by guilherme on 24/10/24.
//

#ifndef QUEENMOVEMENTRULE_H
#define QUEENMOVEMENTRULE_H
#include <vector>

#include "Directions.h"
#include "MovimentRule.h"
template <typename T>
using Ref = std::shared_ptr<T>;
class QueenMovementRule : public MovimentRule {
    public:
    std::vector<Ref<PossibleMove>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) override {
        std::vector<Ref<PossibleMove>> moves;
        Directions topRightDiagonal(1, 1);
        Directions topLeftDiagonal (1,-1);
        Directions bottomRightDiagonal(-1,1);
        Directions bottomLeftDiagonal(-1,-1);

        Directions front(1,0);
        Directions back(-1,0);

        Directions left(0,1);
        Directions right(0,-1);

        std::vector diagonalDirections = {topRightDiagonal,topLeftDiagonal,bottomRightDiagonal,bottomLeftDiagonal,front, back, left, right};

        for (const auto& direction: diagonalDirections) {
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
#endif //QUEENMOVEMENTRULE_H

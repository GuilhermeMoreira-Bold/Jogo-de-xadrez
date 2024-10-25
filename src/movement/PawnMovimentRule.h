//
// Created by guilherme on 18/10/24.
//

#ifndef PAWNMOVIMENTRULE_H
#define PAWNMOVIMENTRULE_H
//
// Created by guilherme on 17/10/24.
//

#include <vector>

template <typename T>
using Ref = std::shared_ptr<T>;

class PawnMovimentRule : public MovimentRule {
public:
    PawnMovimentRule(){};
    std::vector<Ref<PossibleMove>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) override {
        std::vector<Ref<PossibleMove>> moves;
        moves.clear();
        int direction = piece->isBlack ? 1 : -1;
        if (piece-> row + direction <= 7 && piece-> row + direction >= 0) {
            if(board->positions[piece->row + direction][piece->col] == nullptr ) {
                if (board->positions[piece->row + 2 * direction][piece->col] == nullptr && piece->isFirstMove) {
                    moves.push_back(std::make_shared<PossibleMove>(piece->row + 2 * direction, piece->col));
                    moves.push_back(std::make_shared<PossibleMove>(piece->row + 1 * direction, piece->col));
                }else{
                moves.push_back(std::make_shared<PossibleMove>(piece->row + 1 * direction, piece->col));
                }
            }

            if (board->positions[ piece->row + direction][piece->col + direction] && board->positions[ piece->row + direction][piece->col + direction]->isBlack != piece->isBlack) {
                moves.push_back(std::make_shared<PossibleMove>(piece->row + direction, piece->col + direction));
            }

            if (board->positions[ piece->row + direction][piece->col - direction] && board->positions[piece->row + direction][piece->col - direction]->isBlack != piece->isBlack) {
                moves.push_back(std::make_shared<PossibleMove>(piece->row + direction, piece->col - direction));
            }
        }
        return moves;
    };
};


#endif //PAWNMOVEMENTRULE_H

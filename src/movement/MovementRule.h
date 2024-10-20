//
// Created by guilherme on 17/10/24.
//

#ifndef MOVEMENTRULE_H
#define MOVEMENTRULE_H
#include <memory>

#include "PossibleMoves.h"
#include "../board/Board.h"
#include "../pieces/Piece.h"

class Piece;
struct Board;
template<typename T>
using Ref = std::shared_ptr<T>;

class MovementRule {
    public:
    virtual ~MovementRule() = default;

    virtual std::vector<Ref<PossibleMoves>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) = 0;
};


#endif //MOVEMENTRULE_H

//
// Created by guilherme on 17/10/24.
//

#ifndef MOVEMENTRULE_H
#define MOVEMENTRULE_H
#include <memory>
#include "PossibleMove.h"

class Piece;
struct Board;
template<typename T>
using Ref = std::shared_ptr<T>;

class MovimentRule {
    public:
    virtual ~MovimentRule() = default;

    virtual std::vector<Ref<PossibleMove>> validMoviments(std::shared_ptr<Board> board,Ref<Piece> piece) = 0;
};


#endif //MOVEMENTRULE_H

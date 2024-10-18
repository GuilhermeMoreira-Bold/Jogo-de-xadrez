//
// Created by guilherme on 17/10/24.
//

#ifndef MOVEMENTRULE_H
#define MOVEMENTRULE_H
#include <memory>
#include "../pieces/Piece.h"
template<typename T>
using Ref = std::shared_ptr<T>;

class MovementRule {
    public:
    virtual bool isValid(Ref<Piece> piece);
};


#endif //MOVEMENTRULE_H

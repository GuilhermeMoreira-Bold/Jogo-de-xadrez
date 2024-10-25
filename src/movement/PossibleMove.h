//
// Created by guilherme on 18/10/24.
//

#ifndef POSSIBLEMOVES_H
#define POSSIBLEMOVES_H

struct PossibleMove {
    int row, col;
    PossibleMove(int row, int col) : row(row), col(col) {};
    virtual ~PossibleMove() {};
};
#endif //POSSIBLEMOVES_H

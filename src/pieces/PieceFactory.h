//
// Created by guilherme on 16/10/24.
//

#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H
#include <memory>
#include <unordered_map>

#include "Bishop.h"
#include "Horse.h"
#include "King.h"

#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "PieceName.h"
#include "Queen.h"
#include "Rook.h"
#include "../renderer/Renderer.h"

struct PiecesInfo {
    std::string texturePath;
    bool isBlack;
};

class PieceFactory {
public:
        std::unordered_map<PieceName, PiecesInfo> pieces;
        PieceFactory() {
            pieces[PieceName::BLACK_KING] ={"/home/guilherme/CLionProjects/Chess/assets/all/b_king.png",true};
            pieces[PieceName::BLACK_QUEEN] = {"/home/guilherme/CLionProjects/Chess/assets/all/b_queen.png", true};
            pieces[PieceName::BLACK_BISHOP] = {"/home/guilherme/CLionProjects/Chess/assets/all/b_bishop.png", true};
            pieces[PieceName::BLACK_PAWN] = {"/home/guilherme/CLionProjects/Chess/assets/all/b_pawn.png", true};
            pieces[PieceName::BLACK_ROOK] = {"/home/guilherme/CLionProjects/Chess/assets/all/b_rook.png", true};
            pieces[PieceName::BLACK_KNIGHT] = {"/home/guilherme/CLionProjects/Chess/assets/all/b_knight.png", true};

            pieces[PieceName::WHITE_KING] = {"/home/guilherme/CLionProjects/Chess/assets/all/w_king.png", false};
            pieces[PieceName::WHITE_QUEEN] = {"/home/guilherme/CLionProjects/Chess/assets/all/w_queen.png", false};
            pieces[PieceName::WHITE_BISHOP] = {"/home/guilherme/CLionProjects/Chess/assets/all/w_bishop.png", false};
            pieces[PieceName::WHITE_PAWN] = {"/home/guilherme/CLionProjects/Chess/assets/all/w_pawn.png", false};
            pieces[PieceName::WHITE_ROOK] = {"/home/guilherme/CLionProjects/Chess/assets/all/w_rook.png", false};
            pieces[PieceName::WHITE_KNIGHT] = {"/home/guilherme/CLionProjects/Chess/assets/all/w_knight.png", false};
        };
      std::shared_ptr<Piece> create(PieceName name, int row, int col) {
            switch (name) {
                case PieceName::BLACK_PAWN:
                    return std::make_shared<Pawn>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::BLACK_BISHOP:
                    return std::make_shared<Bishop>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::BLACK_KING:
                    return std::make_shared<King>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::BLACK_KNIGHT:
                    return std::make_shared<Knight>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::BLACK_QUEEN:
                    return std::make_shared<Queen>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::BLACK_ROOK:
                    return std::make_shared<Rook>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::WHITE_PAWN:
                    return std::make_shared<Pawn>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::WHITE_BISHOP:
                    return std::make_shared<Bishop>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::WHITE_ROOK:
                    return std::make_shared<Rook>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::WHITE_KING:
                    return std::make_shared<King>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::WHITE_KNIGHT:
                    return std::make_shared<Knight>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                case PieceName::WHITE_QUEEN:
                    return std::make_shared<Queen>(row, col, Renderer::createTexture(&pieces[name].texturePath), pieces[name].isBlack);
                default:
                    return nullptr;
            }
      };
};



#endif //PIECEFACTORY_H

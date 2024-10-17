#include <SDL2/SDL.h>
#include <iostream>
#include <SDL_image.h>

#include "board/Board.h"
#include "pieces/Piece.h"
#include "pieces/PieceFactory.h"
#include "renderer/Renderer.h"
// a tile from 8x8

template <typename T>
using Ref = std::shared_ptr<T>;

void createBoard() {
    Board board;

    SDL_Texture *darkSquareTexture = Renderer::getInstance().createTexture(&board.darkSquare);
    SDL_Texture *lightSquareTexture = Renderer::getInstance().createTexture(&board.lightSquare);

    bool isWhite = false;
    bool isNextLine = false;
    SDL_Rect destRect;

    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            destRect.x = 80 * x;
            destRect.y = 80 * y;
            destRect.w = 80;
            destRect.h = 80;
            if(isNextLine) {
                if(!isWhite) {
                    isWhite = true;
                    Renderer::getInstance().draw(&destRect, lightSquareTexture);
                }else {
                    isWhite = false;
                    Renderer::getInstance().draw(&destRect, darkSquareTexture);
                }
            }else {
                if(isWhite) {
                    isWhite = false;
                    Renderer::getInstance().draw(&destRect, lightSquareTexture);
                }else {
                    isWhite = true;
                    Renderer::getInstance().draw(&destRect, darkSquareTexture);
                }
            }
        }
        isNextLine = !isNextLine;
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Chess", 100, 100, 640, 640, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "Falha ao inicializar IMG_Init: " << IMG_GetError() << std::endl;
        return -1;
    }

    Renderer::init(win);

    createBoard();

    Ref factory = std::make_unique<PieceFactory>();
    for(int x = 0; x < 9; x++) {
        Ref pawn = factory->create(PieceName::WHITE_PAWN, 7,x);
        Renderer::getInstance().draw(pawn->pieceRect,pawn->texture);
    }

    for(int x = 0; x < 9; x++) {
        Ref pawn = factory->create(PieceName::BLACK_PAWN, 2,x);
        Renderer::getInstance().draw(pawn->pieceRect,pawn->texture);
    }

    Ref whiteKing = factory->create(PieceName::WHITE_KING, 8,5);
    Renderer::getInstance().draw(whiteKing->pieceRect,whiteKing->texture);

    Ref whiteQueen = factory->create(PieceName::WHITE_QUEEN, 8,4);
    Renderer::getInstance().draw(whiteQueen->pieceRect,whiteQueen->texture);

    Ref whiteBishop1 = factory->create(PieceName::WHITE_BISHOP, 8,3);
    Renderer::getInstance().draw(whiteBishop1->pieceRect,whiteBishop1->texture);


    Ref whiteBishop2 = factory->create(PieceName::WHITE_BISHOP, 8,6);
    Renderer::getInstance().draw(whiteBishop2->pieceRect,whiteBishop2->texture);

    Ref whiteHorse1 = factory->create(PieceName::WHITE_KNIGHT, 8,2);
    Renderer::getInstance().draw(whiteHorse1->pieceRect,whiteHorse1->texture);


    Ref whiteHorse2 = factory->create(PieceName::WHITE_KNIGHT, 8,7);
    Renderer::getInstance().draw(whiteHorse2->pieceRect,whiteHorse2->texture);

    Ref whiteRook1 = factory->create(PieceName::WHITE_ROOK, 8,1);
    Renderer::getInstance().draw(whiteRook1->pieceRect,whiteRook1->texture);

    Ref whiteRook2 = factory->create(PieceName::WHITE_ROOK, 8,8);
    Renderer::getInstance().draw(whiteRook2->pieceRect,whiteRook2->texture);


    Ref blackKing = factory->create(PieceName::BLACK_KING, 1, 5);
    Renderer::getInstance().draw(blackKing->pieceRect, blackKing->texture);

    Ref blackQueen = factory->create(PieceName::BLACK_QUEEN, 1, 4);
    Renderer::getInstance().draw(blackQueen->pieceRect, blackQueen->texture);

    Ref blackBishop1 = factory->create(PieceName::BLACK_BISHOP, 1, 3);
    Renderer::getInstance().draw(blackBishop1->pieceRect, blackBishop1->texture);

    Ref blackBishop2 = factory->create(PieceName::BLACK_BISHOP, 1, 6);
    Renderer::getInstance().draw(blackBishop2->pieceRect, blackBishop2->texture);

    Ref blackKnight1 = factory->create(PieceName::BLACK_KNIGHT, 1, 2);
    Renderer::getInstance().draw(blackKnight1->pieceRect, blackKnight1->texture);

    Ref blackKnight2 = factory->create(PieceName::BLACK_KNIGHT, 1, 7);
    Renderer::getInstance().draw(blackKnight2->pieceRect, blackKnight2->texture);

    Ref blackRook1 = factory->create(PieceName::BLACK_ROOK, 1, 1);
    Renderer::getInstance().draw(blackRook1->pieceRect, blackRook1->texture);

    Ref blackRook2 = factory->create(PieceName::BLACK_ROOK, 1, 8);
    Renderer::getInstance().draw(blackRook2->pieceRect, blackRook2->texture);



    Renderer::getInstance().render();
    while(true) {
        SDL_Event event;
        if (SDL_WaitEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN) {
                break;
            }
        }
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}

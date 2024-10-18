//
// Created by guilherme on 17/10/24.
//

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "GameSettings.h"
#include "board/Board.h"
#include "board/Square.h"
#include "pieces/PieceFactory.h"
#include "renderer/Renderer.h"
#include "pieces/Piece.h"

template<typename T>
using Ref =  std::shared_ptr <T>;

namespace Chess {
    class Game {
    public:
    Game() {
        init();
    };
    ~Game() {
        shutDown();
    };

    void run() {
        while(true) {
            SDL_Event event;
            if (SDL_WaitEvent(&event)) {
                if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN) {
                    break;
                }
                handleEvent(event);
            }
        }
    };

    private:
    Ref<Square> square;
    SDL_Window* window;
    Ref<Piece> pieces[64] = {};
    int pieceQuantity = 0;
    bool isRunning = true;
    int getPieceQuanitity() {
        return pieceQuantity++;
    }

    void init() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        }

        SDL_Window *win = SDL_CreateWindow("Chess", 100, 100, GameSettings::WINDOW_WIDTH, GameSettings::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (win == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
        }


        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
            std::cerr << "Falha ao inicializar IMG_Init: " << IMG_GetError() << std::endl;
        }

        Renderer::init(win);
        createBoard();

        Ref factory = std::make_unique<PieceFactory>();


        for(int x = 0; x < 8; x++) {
            pieces[getPieceQuanitity()] = std::move(factory->create(PieceName::WHITE_PAWN, 6,x));
        }

        for(int x = 0; x < 8; x++) {
            pieces[getPieceQuanitity()] = std::move(factory->create(PieceName::BLACK_PAWN, 1,x));
        }

        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_KING, 7, 4));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_QUEEN, 7, 3));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_BISHOP, 7, 2));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_BISHOP, 7, 5));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_KNIGHT, 7, 1));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_KNIGHT, 7, 6));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_ROOK, 7, 0));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::WHITE_ROOK, 7, 7));

        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_KING, 0, 4));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_QUEEN, 0, 3));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_BISHOP, 0, 2));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_BISHOP, 0, 5));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_KNIGHT, 0, 1));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_KNIGHT, 0, 6));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_ROOK, 0, 0));
        pieces[getPieceQuanitity()]  = std::move(factory->create(PieceName::BLACK_ROOK, 0, 7));


        square = std::make_shared<Square>(pieces);


        Renderer::getInstance().render();
    };

    void createBoard() {
        Board board;

        SDL_Texture *darkSquareTexture = Renderer::getInstance().createTexture(&board.darkSquare);
        SDL_Texture *lightSquareTexture = Renderer::getInstance().createTexture(&board.lightSquare);

        bool isWhite = false;
        bool isNextLine = false;
        SDL_Rect destRect;

        for(int y = 0; y < 8; y++) {
            for(int x = 0; x < 8; x++) {
                destRect.x = GameSettings::TILE_SIZE * x;
                destRect.y = GameSettings::TILE_SIZE * y;
                destRect.w = GameSettings::TILE_SIZE;
                destRect.h = GameSettings::TILE_SIZE;
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
    void shutDown() {
        SDL_DestroyWindow(window);
        SDL_Quit();
    };
    void handleEvent(SDL_Event &event) {
        switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                int x = event.motion.x / GameSettings::TILE_SIZE;
                int y = event.motion.y / GameSettings::TILE_SIZE;
                std::cout <<"Mouse position:" <<"x: " << x << " y: " << y << std::endl;
                std::shared_ptr<Piece> piece = square->positions[y][x];
                if(piece) {
                    Renderer::getInstance().clear();
                    createBoard();
                    int oldX = piece->row;
                    int oldY = piece->col;
                    piece->move();
                    square->changePiecePosition(oldX, oldY,piece);
                    for(int i = 0; i < 64; i ++) {
                        if(pieces[i] != nullptr) {
                            Renderer::draw(pieces[i]->pieceRect, pieces[i]->texture);
                        }
                    }
                    Renderer::getInstance().render();
                }else {
                    std::cout << "Piece not found" << std::endl;
                };
                break;
        }
    }
};


}

#endif //GAME_H

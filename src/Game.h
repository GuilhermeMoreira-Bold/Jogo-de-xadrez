//
// Created by guilherme on 17/10/24.
//

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "GameSettings.h"
#include "Ui.h"
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
        Square square;
        SDL_Texture* darkSquareTexture;
        SDL_Texture* lightSquareTexture;
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
        Ref<Board> board;
        SDL_Window* window;
        Ref<Piece> pieces[64] = {};
        Ui ui;
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
        darkSquareTexture = Renderer::getInstance().createTexture(&square.darkSquare);
        lightSquareTexture = Renderer::getInstance().createTexture(&square.lightSquare);
        renderBoard();

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


        board = std::make_shared<Board>(pieces);

        Renderer::render();
    };

    void renderBoard() {
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
    void handleClickedPiece(std::shared_ptr<Piece> clickedPiece) {
        std::vector<Ref<PossibleMove>> possibleMoves = clickedPiece->movementRule->validMoviments(board, clickedPiece);
        ui.piecePossiblePositions(possibleMoves);
        SDL_Event pieceEvent;
        while(SDL_WaitEvent(&pieceEvent)) {
            if (pieceEvent.type == SDL_MOUSEBUTTONDOWN) {
                int col = pieceEvent.motion.x / GameSettings::TILE_SIZE;
                int row = pieceEvent.motion.y / GameSettings::TILE_SIZE;
                for (Ref<PossibleMove> const& move : possibleMoves) {
                    if (move->row == row && move->col == col) {
                        int oldRow = clickedPiece->row;
                        int oldCol = clickedPiece->col;
                        clickedPiece->move(col, row);
                        board->changePiecePosition(oldRow, oldCol,clickedPiece);
                    }
                }
                Renderer::clear();
                renderBoard();
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (board->positions[x][y] != nullptr) {
                            Renderer::draw(board->positions[x][y]->pieceRect,board->positions[x][y]->texture);
                        }
                    }
                }
                Renderer::getInstance().render();
                break;
            }

        }
    }


    void handleEvent(SDL_Event &event) {
        switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                int mousePositionX = event.motion.x / GameSettings::TILE_SIZE;
                int mousePositionY = event.motion.y / GameSettings::TILE_SIZE;
                std::shared_ptr<Piece> clickedPiece = board->positions[mousePositionY][mousePositionX];
                if(clickedPiece) {
                    handleClickedPiece(clickedPiece);
                }
                break;
        }
    }
};

}
#endif //GAME_H

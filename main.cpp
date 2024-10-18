#include <SDL2/SDL.h>
#include <iostream>
#include <SDL_image.h>

#include "src/Game.h"
#include "src/board/Board.h"
#include "src/pieces/Piece.h"
#include "src/pieces/PieceFactory.h"
#include "src/renderer/Renderer.h"
// a tile from 8x8

template <typename T>
using Ref = std::shared_ptr<T>;



int main() {
    Chess::Game game;
    game.run();
    return 0;
}
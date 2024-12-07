cmake_minimum_required(VERSION 3.29)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Chess main.cpp
        src/pieces/Piece.h
        src/pieces/Pawn.h
        src/renderer/Renderer.h
        src/renderer/Renderer.cpp
        src/board/Square.h
        src/pieces/PieceFactory.h
        src/pieces/PieceName.h
        src/pieces/Bishop.h
        src/pieces/Knight.h
        src/pieces/Rook.h
        src/pieces/King.h
        src/pieces/Queen.h
        src/movement/MovimentRule.h
        src/board/Board.h
        src/Game.h
        src/GameSettings.h
        src/Ui.h
        src/movement/PossibleMove.h
        src/movement/PawnMovimentRule.h
        src/movement/BishopMovementRule.h
        src/movement/Directions.h
        src/movement/QueenMovementRule.h
        src/movement/KMovimentRule.h
        src/movement/KnightMovimenteRule.h
        src/movement/RookMovimentRule.h
)

target_link_libraries(Chess ${SDL2_LIBRARIES} SDL2_image)

message(STATUS "SDL2 include dirs: ${SDL2_INCLUDE_DIRS}")


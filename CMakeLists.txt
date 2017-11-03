cmake_minimum_required(VERSION 3.6)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.h Board.h Minimax.h)
add_executable(TicTacToe ${SOURCE_FILES})
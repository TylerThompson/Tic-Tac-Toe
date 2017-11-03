/**
 * Tyler Thompson
 * Intro Into Artificial Intelligence
 *
 * The purpose of this project is to use the Minimax Algorithm
 * in order to play against the computer, or you may play against
 * another human and test your skills.
 */

#ifndef MINIMAX_H
#define MINIMAX_H

#include <iostream>
#include <vector>
#include <set>
#include "Board.h"

class Minimax {
private:
    struct AI {
        int x, y, score;
        AI(){}
        AI(int _s):score(_s){}
        AI(int _x, int _y){x = _x, y = _y;}
    };
public:
    /**
 * makeMove
 * determine best move, calculate score for
 * each choice and choose best one and make the move
 * @param board
 * @param p
 */
    void makeMove(Board& board, player p){
        AI bestMove = getBestMove(board, p);
        cout<<"Computer Score: "<<bestMove.score*-1<<endl;
        board.setVal(bestMove.x, bestMove.y, p);
    }
    /**
 * getBestMove
 * determine what the best move for the
 * computer to take
 * @param board
 * @param playerTurn
 * @return
 */
    AI getBestMove(Board& board, player playerTurn){

        state gameState = board.checkWin(playerTurn);
        if(gameState == win){
            return AI(10);
        }else if(gameState == lose){
            return AI(-10);
        }else if(gameState == draw){
            return AI(0);
        }

        vector<AI>moves;

        for (int i = 0; i<board.getSize(); i++) {
            for (int j = 0; j<board.getSize(); j++) {
                if(board.isEmpty(i,j)){
                    AI move;
                    move.x = i; move.y = j;
                    board.setVal(i, j, playerTurn);

                    if(playerTurn == computer){
                        move.score = getBestMove(board, human).score;
                    } else {
                        move.score = getBestMove(board, computer).score;
                    }
                    moves.push_back(move);
                    board.setVal(i,j,empty);
                }
            }
        }

        int bestMove = 0;
        if(playerTurn == computer){
            int min = 3;
            for (int i = 0; i<moves.size(); i++) {
                if(moves[i].score < min) min = moves[i].score, bestMove = i;
            }
        } else {
            int max = 3;
            for (int i = 0; i<moves.size(); i++) {
                if(moves[i].score > max) max = moves[i].score, bestMove = i;
            }
        }
        return moves[bestMove];
    }
};
#endif //MINIMAX_H
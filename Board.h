/**
 * Tyler Thompson
 * Intro Into Artificial Intelligence
 *
 * The purpose of this project is to use the Minimax Algorithm
 * in order to play against the computer, or you may play against
 * another human and test your skills.
 */
#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <iostream>
#include <iomanip>

using namespace std;

enum state{
    nothing,win,lose,draw
};

enum player{
    human, computer, empty
};

class Board{
private:
    int size;
    bool turn;
    int count;
    char matrix[3][3] = {
            {' ',' ',' '},
            {' ',' ',' '},
            {' ',' ',' '}
    };
public:
    /**
 * Constructor
 * not much to be said about constructor
 * @param size
 */
    Board(int s = 3){
        size = s;
        turn = false;
        count = 0;
    }
    /**
 * DisplayMatrix
 * Show the game board interface in the terminal
 */
    void displayMatrix(){
        for(int i = 0; i<3; i++) cout<<endl;
        for (int i = 0; i<size; i++) {
            for (int j = 0; j<size; j++) {
                cout<<setw(3)<<matrix[i][j]<<setw(3);
                if (j<2) {
                    cout<<"|"<<setw(3);
                }
            }
            cout<<endl;
            for (int j = 0; j<3; j++) {
                if (i<2) {
                    cout<<setw(3)<<"---"<<setw(3)<<"---"<<setw(3);
                }
            }
            cout<<endl;
        }
    }
    /**
 * validate
 * Check if the element position has already been taken or not
 * @param x
 * @param y
 * @return
 */
    bool validate(int x, int y){
        //Check first if the element is empty then check if the x and y are in range
        if (matrix[x][y] == ' ') {
            return (x >= 0 && x < 3) && (y >= 0 && y < 3);
        }
        return false;
    }
    /**
     * checkWin
     * check if the player/computer has won and return the state
     * of that decision
     * @param p
     * @return
     */
    state checkWin(player p){
        // todo: i think i can out
        // Check diagonal from left to right down
        if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != ' ') {
            return p != human ? win : lose;
        } else if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != ' ') {
            // check diagonal from right to left down
            return p != human ? win : lose;
        } else if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && ' ' != matrix[0][2] ) {
            // First Row
            return p != human ? win:lose;
        }else if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != ' '){
            // Diagonal Row from right to left
            return p != human ? win:lose;
        }else if(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]  && matrix[1][0] != ' '){
            // First Col
            return p != human ? win:lose;
        }else if(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]  && matrix[1][2] !=' '){
            // Third Col
            return p != human ? win:lose;
        }else if(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && matrix[2][1] != ' '){
            // Third Row
            return p != human ? win:lose;
        }else if(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && matrix[1][1] != ' '){
            //Second Col
            return p != human ? win:lose;
        }else if(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][1] != ' '){
            //Second Row
            return p != human ? win:lose;
        }else if(count==9){
            return draw;
        }else{
            return nothing;
        }
    }
    /**
     * Set the value of the player/computer move
     * @param x
     * @param y
     * @param p
     */
    void setVal(int x, int y, player p){
        if(p!=empty)
            matrix[x][y] = p == human ? 'X':'O', count++;
        else
            matrix[x][y] = ' ', count--;
    }
    /**
 * clear
 * clear the board matrix to play again
 */
    void clear(){
        count = 0;
        for (int i = 0; i<size; i++)
            for (int j = 0; j<size; j++)
                matrix[i][j] = ' ';
    }
    /**
     * isEmpty
     * check if the array position is empty
     */
    bool isEmpty(int x, int y)const{return matrix[x][y] == ' ';};
    /**
     * getSize
     * @return
     */
    int getSize()const{return size;}
};
#endif //TICTACTOE_BOARD_H
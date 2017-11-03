/**
 * Tyler Thompson
 * Intro Into Artificial Intelligence
 *
 * The purpose of this project is to use the Minimax Algorithm
 * in order to play against the computer, or you may play against
 * another human and test your skills.
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Minimax.h"

class Game{
private:
    bool turn;
    bool isMultiplayer;
    int choice;
    Board board;
    Minimax aiPlayer, aiPlayer_2;
public:
    Game(){
        turn = true;
        isMultiplayer = false;
        cout<<"+---------------------------------------------------------------+"<<endl;
        cout<<endl<<"|\t\t\tWelcome to Tic-Tac-Toe\t\t\t|"<<endl<<endl;
        printInstructions();
    };
    /**
 * newGame
 * create a new game
 */
    void newGame(){
        board.clear();
        cout<<"(0)Single"<<endl<<"(1) Multi-player"<<endl<<"(2)Computer Vs. Computer: "<<endl;
        cin>>choice;
        cout<<endl;
    };
    /**
 * Start
 * start the game
 */
    void start(){
        bool play = true;
        int x = 0, y = 0;
        state current = nothing;
        newGame();

        while (play) {
            while (true) {
                /*
                 *  get the Location of the X/O from the game
                 */
                if(choice == 1){
                    if(!turn){
                        cout<<"Player O: ";
                        cin>>x>>y;
                    } else {
                        cout<<"Player X: ";
                        cin>>x>>y;
                    }
                }else if(choice == 0){
                    if (!turn) {
                        cout<<"Computer:- ";
                        aiPlayer.makeMove(board,computer);
                        turn = !turn;
                        break;
                    } else {;
                        cout<<"Player: ";
                        cin>>x>>y;
                    }
                } else {
                    (!turn)? aiPlayer.makeMove(board,computer) : aiPlayer_2.makeMove(board,human);
                    turn = !turn;
                    break;
                }

                cout<<endl;

                //Validate input is correct
                if (board.validate(x, y)) {
                    board.setVal(x, y, turn ? human:computer);
                    turn = !turn; // Switch turns
                    break;
                } else {
                    if(x>=0 && x<3 && y>=0 && y<3){
                        cerr<<"Error! Location is Taken"<<endl;
                    } else {
                        cerr<<"Error! Location do not exist"<<endl;
                    }
                }
            }

            board.displayMatrix();

            current = board.checkWin(turn ? human:computer);

            //Terminate game
            if (current != nothing) {
                if(!finishGame(current)){
                    play = false;
                } else {
                    newGame();
                }
            }
            cout<<endl;
        }
    };
    /**
 * printInstructions
 * print the instructions of how to use/play the game
 */
    void printInstructions()const {
        cout<<"|\t\t\tInstructions\t\t\t\t|"<<endl;
        cout<<"|\tInput format 2 digits separated by space\t\t|"<<endl;
        cout<<"|\tLocation (0,0) top left and (2,2) bottom right\t\t|"<<endl;
        cout<<"+---------------------------------------------------------------+"<<endl;
    };
    /**
 * Finsih Game
 * Determine if we have won the game or not
 * @param current
 * @return
 */
    bool finishGame(state current){
        switch (current) {
            case win:
                if(isMultiplayer) cout<<"X Wins!!\n";
                else cout<<"You Win!!\n";
                break;
            case lose:
                if(isMultiplayer) cout<<"O Wins!!\n";
                else cout<<"The Computer Wins!!\n";
                break;
            case draw:
                cout<<"It's a Draw"<<endl;
            default:
                break;
        }

        bool again = false;
        cout<<"Play Again: (0)No (1)Yes : ";
        cin>>again;
        return again;
    }
};
#endif //GAME_H
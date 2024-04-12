#ifndef BOARD_H
#define BOARD_H
/*******************************
 * FileName: Board.h
 * Created: 4/8/24
 * Updates:
 * (4/10/24) after some struggle to create a 2d array
 * using just new and built in arrays; I did  some reasearch and
 * I found out I could create one by seperating them in a way.
 * 2d arrays are an array of arrays so you can
 * create the same by having an established pointer to an array of type int
 * and then filling that array with other pointers to an array of type int.
 *
 *
 *
 *
 *
 *
 *
********************************/




#include <array>
#include <cstdlib>
#include <iostream>
#include <string>
using std::string;



class Board
{

    friend std::ostream& operator <<(std::ostream&, Board&);//displays the tic tac toe board
    friend std::istream& operator >>(std::istream&, Board&);//takes an input and draws it on the board it also takes a number to differentiate
    friend void startMenu(Board&);//boots the menu up and creates the board once the user has started the game

    private:


    bool whosPlay{true};//a variable to decide who's play we are on, 1 for player 0 for computer
    string** gameBoard;//pointer to pointer string where tic tac toe is played on
    bool** inBoard;//pointer to pointer bool where we find out if a move was already played in the box
    int inputCount;//the amount of inputs put in the board so far
    int limitSize;//max width and length of boards


    string player{"O"};//the player's string
    string cmptr{"X"};// the computer's string

    void setBoards(int);//sets the limit board and gameboard and their sizes


    public:

    explicit Board();//default constructor sets the playBoard to 3


    //game functions
    void setGame();//sets the board size and starts the game
    void setPlayers();//sets the player to x or o and computer to the opposite


    bool isFull();//checking if the board is completely full
    int gameCheck();//will be called after a move and check if there is a win or tie

    void cmptrMove();//the computer plays a move randomly (THERE IS NO CHECK TO SEE IF IT IS ACTUALLY THE COMPUTER'S MOVE THAT IS DONE IN THE MAIN PROGRAM)


};





#endif
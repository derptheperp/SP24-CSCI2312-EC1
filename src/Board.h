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

    friend std::ostream& operator <<(std::ostream&, Board&);
    friend std::istream& operator <<(std::istream&, Board&);

    private:



    string** gameBoard;//pointer to pointer string where tic tac toe is played on
    bool** inBoard;//pointer to pointer bool where we find out if a move was already played in the box
    string player{"O"};
    string cmptr{"X"};
    int limitSize;//max

    void setBoards(int);//sets the gameBoard and limit board and limit size



    public:

    explicit Board();//default constructor sets the playBoard to 3
    explicit Board(int);

    //getters
    string** getBoard();
    bool** getInBoard();
    int getLimit();


    //game functions
    void displayMenu();
    void setPlayer();//sets the player to x or o and computer to the opposite



};


#endif
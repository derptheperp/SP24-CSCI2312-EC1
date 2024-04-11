#include <iostream>
#include <array>
#include "Board.h"

int main()
{

    Board testBoard;

    startMenu(testBoard);

    std::cout << "\n\nTest game: \n";
    std::cout << testBoard;
    std::cout << "\nEnter the value x,y in that specific format ";
    std::cin >> testBoard;
    std::cout << testBoard;
    std::cout << "\nEnter the value x,y in that specific format ";
    std::cin >> testBoard;
    std::cout << testBoard;



    //testing out how printing looks like in the terminal
    // for(int indx{0}; indx < 4; ++indx)
    // {
    //     for(int ndx{0}; ndx < 4 ; ++ndx)
    //     {
    //         std::cout  << " " << "O" << " ";
    //         if(ndx != 3)
    //         {
    //             std::cout << "|";
    //         }
    //     }
    //     if(indx != 3)
    //     {
    //         std::cout << std::endl << "---------------";

    //     }
    //     std::cout << std::endl;

    // }

    //  - | - | -
    //-------------
    //  - | - | -
    //-------------
    //  - | - | -




}

#include <iostream>
#include <array>
#include "Board.h"

int main()
{
    // std::array<int, BOARD> testBoard;
    // for(int& types : testBoard)
    // {
    //     types = 1;
    //     std::cout << types;
    // }

    // std::cout << "After looping false: " << testBoard.empty();

    Board testBoard(10);

    std::cout << testBoard;
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



}

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <cstddef>

friend std::ostream& operator>>(ostream&, Gameboard&);
friend std::istream& operator<<(istream&, Gameboard&);



class Gameboard
{
    private:

    std::array 


    public:

    Gameboard(bool);
    bool isFull();





};


#endif
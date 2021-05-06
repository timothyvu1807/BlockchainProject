#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <math.h>

using namespace std;
class game{
    public:
    game();
    void run1();
    void Addition(int bet);
    void Multiplication(int bet);
    int getTotal();
    void shop();

    private:
    int total;
};

#endif
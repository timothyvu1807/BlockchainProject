#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Blockchain.h"
#include "game.h"
#include "game.cpp"
#include "sha256.h"
#include "sha256.cpp"

using namespace std;

int main()
{
    game game;
    game.run1();

    string input = "verynice";
    string output1 = sha256(input);
    cout << "sha256('"<< input << "'):" << output1 << endl;
    
    return 0;
}
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <math.h>
#include "Blockchain.h"

using namespace std;

class game{

    public:
    game();
    void run1();
    void Addition(int bet);
    void Multiplication();
    int getTotal();
    void shop();

    private:
    int total;
};

game::game(){
    total = 0;
}

void game::Addition(int bet){
    int rightCounter =0, wrongCounter=0;

    auto start = chrono::steady_clock::now();
    for(int i =0; i<5; i++)
    {
        int num1 = rand()%100, num2 = rand()%100;
        int sum = num1 +num2;
        int userAnswer;
        cout << "what is the sum of " << num1 << " and " << num2 <<endl;
        cin >> userAnswer;
        if(userAnswer == sum)
        {
            cout << "Grats" << endl;
            rightCounter++;
        }else{
            cout << " feelsbad" << endl;
            wrongCounter++;
        }
    }
    auto stop = chrono::steady_clock::now();
    std::chrono::duration<double> difference = stop - start;
    cout << "Time took to run: " << difference.count()<<endl; //need point multiplier based on how fast
    total = rightCounter - wrongCounter;
    if(total <0)
    {
        cout << "bruh you get no money" << endl;
    }else{
    total = total*10;
    cout << "your total score is " << total << endl;
    }
    total = bet +total;
    
}

// void game::Multiplication(){
//     int num1 = rand()%9, num2 = rand()%9;
//     int rightCounter, wrongCounter;
//     //timer

//     while(!timesup)
//     {
//         int product = num1*num2;
//         int userAnswer;
//         cout << "what is the product of" << num1 << " and " << num2 <<endl;
//         cin >> userAnswer;
//         if(userAnswer == product)
//         {
//             cout << "Grats" << endl;
//             rightCounter++;
//         }else{
//             cout << " feelsbad" << endl;
//             wrongCounter++;
//         }
//     }
//     int total = rightCounter - wrongCounter;
//     if(total <0)
//     {
//         cout << "bruh you get no money" << endl;
//     }else{
//     cout << "your total score was" << total << endl;
//     total = total*10;
//     }
// }

int game::getTotal()
{
    return total;
}

void game::run1()
{
    char choice;
    int total = 0;
    int bet;
    cout << "how much do you want to bet in this game?" << endl;
    cin >> bet;
    cout << "Enter 's' to enter the Shop, 'A' to play addition, 'M' to play multiplication, or 'x' to exit:  ";
     do{
     cin>>choice;
     switch(choice){
                    case 'X':
                    case 'x':break;
                    // enter shop
                            
                    case 'A':
                    case 'a':
                            Addition(bet);
                            cout << "The bet was:" << bet<< " and i have " << getTotal();
                    case 'M':
                    case 'm':
                            // cout << "hey" << endl;
                    case 'S': shop();
                    case 's': shop();
                    default: cout<<"Invalid entry. ";
                    }
     }while((choice != 'x') && (choice != 'X'));
}

void game::shop(){
    int choice =0;
    game game;
    cout << endl;
    cout << "Welcome to the shop! Enter which item number you want to purchase." << endl;
    cout << endl;
    cout << "Item 1: 100 points" << endl;
    cout << "Item 2: 500 points" << endl;
    cout << "Item 3: 1000 points" << endl; 
    cin >> choice;
    if(choice <0 || choice >3){
        cout << "Invalid entry" << endl;
    }
    else
    {   cout << endl;
        switch(choice){
            case '1':
            case '2':
            case '3':
            case 'x': break;
            case 'X': break;
            case 'p': run1();
            case 'P': run1();
            cout << "press X to exit the shop or P to go back to the play menu" << endl;
        }

    }
}

#endif
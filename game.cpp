#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <math.h>
#include <time.h>
#include "Blockchain.h"
#include "Blockchain.cpp"
#include "game.h"

using namespace std;

game::game(){
    total = 100;
}

void game::Addition(int bet){
    auto start = chrono::steady_clock::now();

    srand(time(0));
    for(int i = 0; i< 5; i++)
    {
        int num1 = rand()%100, num2 = rand()%100;
        int sum = num1 +num2;
        int userAnswer;
        cout << "What is the sum of " << num1 << " and " << num2 <<endl;
        cin >> userAnswer;
        if(userAnswer == sum)
        {
            cout << "Grats" << endl;
            total = total +bet;
        }else{
            cout << "Feelsbad" << endl;
            total = total -bet;
        }
    }
    auto stop = chrono::steady_clock::now();
    std::chrono::duration<double> difference = stop - start;
    cout << "Time took to run: " << difference.count()<<endl; //need point multiplier based on how fast
    if(total <0)
    {
        cout << "bruh you get no money" << endl;
    }else{
    cout << "Your total score is " << total << endl;
    }
    
}

void game::Multiplication(int bet){
    // int rightCounter = 0, wrongCounter = 0;
    auto start = chrono::steady_clock::now();
    
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        int num1 = rand()%12, num2 = rand()%12;
        int product = num1 * num2;
        int userAnswer = 0;
        bet = bet*2;
        cout << "What is the multiplication of " << num1 << " and " << num2 << endl;
        cin >> userAnswer;

        if (userAnswer == product)
        {
            cout << "Good Job!" << endl; 
            total = total + bet;
        }else{
            cout << "Feelsbad" << endl;
            total = total - bet;
        }
    }
    auto stop = chrono::steady_clock::now();
    std::chrono::duration<double> difference = stop - start;
    cout << "Time took to run: " << difference.count()<<endl; //need point multiplier based on how fast
    if(total <0)
    {
        cout << "Bruh you get no money" << endl;
    }else{
    cout << "Your total score is " << total << endl;
    }
    
}

int game::getTotal()
{
    return total;
}

void game::run1()
{
    char choice;
    int bet =0;
    cout << "You have this much money: " << total << endl;
    cout << "How much do you want to bet in this game?" << endl;
    cin >> bet;
    cout << "Enter 'S' to enter the Shop, 'A' to play addition, 'M' to play multiplication, or 'X' to exit:  ";
     do{
     cin>>choice;
     switch(choice){
                    case 'X':
                    case 'x':break; 
                    case 'a':
                            Addition(bet);
                            cout << "The bet was:" << bet<< " and i have " << getTotal();
                    case 'm':
                            Multiplication(bet);
                    case 'S': shop();
                    case 's': shop();
                    default: cout<<"Invalid entry. ";
                    }
     }while((choice != 'x') && (choice != 'X'));
}

void game::shop(){
    do{
        Blockchain coin;
        time_t data1Time;
        int choice = 0;
        game game; 
        cout << endl;
        cout << "Welcome to the shop! Enter which item number you want to purchase." << endl;
        cout << endl;
        cout << "Item 1: 10 points" << endl;
        cout << "Item 2: 50 points" << endl;
        cout << "Item 3: 100 points" << endl; 
        cin >> choice;
        if(choice <0 || choice >3){
            cout << "Invalid entry" << endl;
        }else if(choice == 1)
        {
            total = total - 10;
            if(total <0)
            {
                cout << "insufficient funds" << endl; 
            }else{
            TransactionData data(10, "player", "Shop", time(&data1Time));
            coin.addBlock(data);
            coin.printChain();
            }
        }else if(choice == 2)
        {
            total = total - 100;
            if(total <0)
            {
                cout << "insufficient funds" << endl; 
            }else{
            TransactionData data(50, "player", "Shop", time(&data1Time));
            coin.addBlock(data);
            coin.printChain();
            }
        }else if(choice == 3)
        {
            total = total - 100;
            if(total <0)
            {
                cout << "insufficient funds" << endl;
            }else{
            TransactionData data(100, "player", "Shop", time(&data1Time));
            coin.addBlock(data);
            coin.printChain();
            }
        }
        else
        {   cout << "Enter x to exit the game or p to play the game again" << endl;
            switch(choice){
                case 'x': break;
                case 'X': break;
                case 'p': run1();
                case 'P': run1();
                cout << "press X to exit the shop or P to go back to the play menu" << endl;
            }

        }
    }while(1);
}
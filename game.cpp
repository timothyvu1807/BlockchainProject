#include <iostream>
#include <cstdlib>
#include <chrono>
#include <math.h>
#include <time.h>
#include "Blockchain.h"
#include "Blockchain.cpp"
#include "game.h"

using namespace std;

game::game()
{
    total = 100;
}

void game::Addition(int bet)
{
    auto start = chrono::steady_clock::now();

    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        int num1 = rand() % 100, num2 = rand() % 100;
        int sum = num1 + num2;
        int userAnswer;
        cout << "What is the sum of " << num1 << " and " << num2 << endl;
        cin >> userAnswer;
        if (userAnswer == sum)
        {
            cout << "Congrats!" << endl;
            total = total + bet;
        }
        else
        {
            cout << "Unlucky." << endl;
            total = total - bet;
        }
    }
    auto stop = chrono::steady_clock::now();
    std::chrono::duration<double> difference = stop - start;
    cout << "Time took to run: " << difference.count() << endl; //need point multiplier based on how fast
    if (total < 0)
    {
        cout << "Sorry, you have no money." << endl;
    }
    else
    {
        cout << "Your total score is " << total << endl;
    }
}

void game::Multiplication(int bet)
{
    auto start = chrono::steady_clock::now();
    bet = bet * 2;
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        int num1 = rand() % 12, num2 = rand() % 12;
        int product = num1 * num2;
        int userAnswer = 0;
        cout << "What is the multiplication of " << num1 << " and " << num2 << endl;
        cin >> userAnswer;

        if (userAnswer == product)
        {
            cout << "Good Job!" << endl;
            total = total + bet;
        }
        else
        {
            cout << "Unlucky." << endl;
            total = total - bet;
        }
    }
    auto stop = chrono::steady_clock::now();
    std::chrono::duration<double> difference = stop - start;
    cout << "Time took to run: " << difference.count() << endl; //need point multiplier based on how fast
    if (total < 0)
    {
        cout << "Sorry, you have no money." << endl;
    }
    else
    {
        cout << "Your total score is " << total << endl;
    }
}

void game::MixOfTheTwo(int bet)
{
    auto start = chrono::steady_clock::now();
    srand(time(0));

    bet = bet * 3;
    for (int i = 0; i < 5; i++)
    {
        int randomNum1 = rand() % 100;
        // cout << "Test Number: " << randomNum1 << endl;
        if (randomNum1 % 2 == 0)
        {
            //Addition
            int num1 = rand() % 50, num2 = rand() % 50;
            int sum = num1 + num2;
            int userAnswer;
            cout << "What is the sum of " << num1 << " and " << num2 << endl;
            cin >> userAnswer;

            if (userAnswer == sum)
            {
                cout << "Congrats!" << endl;
                total = total + bet;
            }
            else
            {
                cout << "Unlucky." << endl;
                total = total - bet;
            }
        }
        else
        {
            //Multiplication
            int num1 = rand() % 12, num2 = rand() % 12;
            int product = num1 * num2;
            int userAnswer = 0;
            //bet = bet * 2;
            cout << "What is the multiplication of " << num1 << " and " << num2 << endl;
            cin >> userAnswer;

            if (userAnswer == product)
            {
                cout << "Good Job!" << endl;
                total = total + bet;
            }
            else
            {
                cout << "Unlucky." << endl;
                total = total - bet;
            }
        }
    }

    auto stop = chrono::steady_clock::now();
    std::chrono::duration<double> difference = stop - start;
    cout << "Time took to run: " << difference.count() << endl; //need point multiplier based on how fast
    if (total < 0)
    {
        cout << "Sorry, you have no money." << endl;
    }
    else
    {
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
    int bet = 0;
    cout << "You have this much money: " << total << endl;
    cout << "How much do you want to bet in this game?" << endl;
    cin >> bet;
    //cout << "Enter 'S' to enter the Shop, 'A' to play addition, 'M' to play multiplication, 'B' to play Mix of + and *, or 'X' to exit:  ";
    do
    {
        cout << "Enter 'S' to enter the Shop, 'A' to play addition, 'M' to play multiplication, 'B' to play Mix of + and *, or 'X' to exit:  ";
        cin >> choice;
        if(choice == 'x' || choice == 'X')
        {
            break;
        }else if(choice == 'a' || choice == 'A')
        {
            Addition(bet);
        }else if(choice == 'm' || choice == 'M')
        {
            Multiplication(bet);
        }else if(choice == 'b' || choice == 'B')
        {
            MixOfTheTwo(bet);
        }else if(choice == 'S' || choice == 's')
        {   
            shop();
        }
    } while ((choice != 'x') || (choice != 'X'));
}

void game::shop()
{
    int choice = 0;
    int counter =0;
    Blockchain coin;
    game game;
    do
    {
        cout << endl;
        cout << "Welcome to the shop! Enter which item number you want to purchase. Press x to exit game." << endl;
        cout << "Your total is " << total << endl;
        cout << endl;
        cout << "Item 1: 10 points" << endl;
        cout << "Item 2: 50 points" << endl;
        cout << "Item 3: 100 points" << endl;
        cin >> choice;
        if (choice < 0 || choice > 3 )
        {
            cout << "Invalid entry" << endl;
        }
       else if (choice == 1)
        {
            total = total - 10;
            if (total < 0)
            {
                cout << "insufficient funds" << endl;
            }
            else
            {  
                time_t data1Time;
                TransactionData data1(10, "player", "Shop", time(&data1Time));
                coin.addBlock(data1);
                coin.printChain();
            }
        }
        else if (choice == 2)
        {
            total = total - 100;
            if (total < 0)
            {
                cout << "insufficient funds" << endl;
            }
            else
            {   
                time_t data2Time;
                TransactionData data2(50, "player", "Shop", time(&data2Time));
                coin.addBlock(data2);
                coin.printChain();
            }
        }
        else if (choice == 3)
        {
            total = total - 100;
            if (total < 0)
            {
                cout << "Insufficient funds" << endl;
            }
            else
            {   
                time_t data3Time;
                TransactionData data3(100, "player", "Shop", time(&data3Time));
                coin.addBlock(data3);
                coin.printChain();
            }
        }
        else
        {
            char choice1;
            cout << "Enter x to exit the game or p to play the game again" << endl;
            switch (choice1)
            {
            case 'x':
                break;
            case 'X':
                break;
            case 'p':
                run1();
            case 'P':
                run1();
                cout << "press X to exit the shop or P to go back to the play menu" << endl;
            }
        }
    } while (choice < 4);

}
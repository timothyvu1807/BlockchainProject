#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "game.h"
using namespace std;

// Transaction
struct TransactionData
{
    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;

    TransactionData(){};

    TransactionData(double amt, string sender, string receiver, time_t time)
    {
        amount = amt;
        senderKey = sender;
        receiverKey = receiver;
        timestamp = time;
    };
};

// Block
class Block
{
private:
    int index;
    string blockHash;
    string previousHash;
    string generateHash();

public:
    Block(int idx, TransactionData d, string prevHash);
    int getIndex();
    string getHash();
    string getPreviousHash();
    TransactionData data;
    bool isHashValid();
};

#endif
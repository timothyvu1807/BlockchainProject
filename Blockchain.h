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
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;
    
    TransactionData(){};
    TransactionData(int amt, std::string sender, std::string receiver, time_t time)
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
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();
    
public:
    Block(int idx, TransactionData d, size_t prevHash);
    int getIndex();
    size_t getHash();
    size_t getPreviousHash();
    TransactionData data;
    bool isHashValid();
};

class Blockchain
{
private:
    Block createGenesisBlock();
    std::vector<Block> chain;

public:
    // Constuctor
    Blockchain();
    
    // Public Functions
    vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

#endif
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

// Transaction
struct TransactionData{
    double amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;
    
    TransactionData(){};
    
    TransactionData(double amt, std::string sender, std::string receiver, time_t time)
    {
        amount = amt;
        senderKey = sender;
        receiverKey = receiver;
        timestamp = time;
    };
};

// Block
class Block{
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

Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

int Block::getIndex()
{
    return index;
}

size_t Block::generateHash()
{
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);
    std::hash<std::string> tDataHash;
    std::hash<std::string> prevHash;
    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == getHash();
}

// Blockchain
class Blockchain{
private:
    Block createGenesisBlock();
    std::vector<Block> chain;

public:
    // Constuctor
    Blockchain();
    
    // Public Functions
    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

// Public Chain Getter
std::vector<Block> Blockchain::getChain() {
    return chain;
}

// Create Genesis Block
Block Blockchain::createGenesisBlock()
{
    // Get Current Time
    std::time_t current;
    
    // Setup Initial Transaction Data
    TransactionData d(0, "Genesis", "Genesis", time(&current));
    
    // Return Genesis Block
    Block genesis(0, d, 0);
    return genesis;
}

// We only need pointer here
// to demonstrate manipulation of transaction data
Block *Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size();
    std::size_t previousHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid()
{
    std::vector<Block>::iterator it;
    
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }
        
        // Don't forget to check if this is the first item
        if (it != chain.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
            {
                return false;
            }
        }
    }
    
    return true;
}

void Blockchain::printChain() {
    std::vector<Block>::iterator it;
    
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        printf("\n\nBlock ===================================");
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount);
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.timestamp);
        printf("\nHash: %zu", currentBlock.getHash());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid?: %d", currentBlock.isHashValid());
    }
}

#endif

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "game.h"
#include "sha256.h"
#include "Blockchain.h"

using namespace std;

Block::Block(int idx, TransactionData d, string prevHash)
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

string Block::generateHash()
{
//     string toHashS = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);
    hash<string> tDataHash;
    hash<string> prevHash;
//     return tDataHash(toHashS) ^ (prevHash(to_string(previousHash)) << 1);
    string input = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);
    string output1 = sha256(input);
    cout << "sha256('"<< input << "'):" << output1 << endl;
    return output1;
}

string Block::getHash()
{
    return blockHash;
}

string Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == getHash();
}

// Blockchain
class Blockchain
{
private:
    void shop();
    Block createGenesisBlock();
    vector<Block> chain;

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

Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

// Public Chain Getter
vector<Block> Blockchain::getChain()
{
    return chain;
}

// Create Genesis Block
Block Blockchain::createGenesisBlock()
{
    // Get Current Time
    time_t current;

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
    string previousHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid()
{
    vector<Block>::iterator it;

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

void Blockchain::printChain()
{
    vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        cout << "\n\nBlock ===================================";
        // cout << "\nIndex: " << currentBlock.getIndex();
        cout << "\nAmount: " << currentBlock.data.amount;
        cout << "\nSenderKey: " << currentBlock.data.senderKey.c_str();
        cout << "\nReceiverKey: " << currentBlock.data.receiverKey.c_str();
        cout << "\nTimestamp: " << currentBlock.data.timestamp;
        cout << "\nHash: " << currentBlock.getHash();
        cout << "\nPrevious Hash: " << currentBlock.getPreviousHash();
    }
}


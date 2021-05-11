#include <vector>
#include <ctime>
#include <string>
#include "game.h"
#include "sha256.h"
#include "Blockchain.h"

using namespace std;

Block::Block(int idx, TransactionData d, size_t previousHash1)
{
    index = idx;
    data = d;
    previousHash = previousHash1;
    blockHash = generateHash();
}

// private functions
int Block::getIndex()
{
    return index;
}

size_t Block::generateHash()
{
    string toHashS = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);
    hash<string> tDataHash; // hashes transaction data string
    hash<string> prevHash; // re-hashes previous hash (for combination)
    return tDataHash(toHashS) ^ (prevHash(to_string(previousHash)) << 1);
}

// Public Functions
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

Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

// Public Chain Getter
vector<Block> Blockchain::getChain() {
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
    size_t previousHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
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

void Blockchain::printChain() {
    vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        string temp = sha256(to_string(currentBlock.getHash()));
        string temp1 = sha256(to_string(currentBlock.getPreviousHash()));
        
        printf("\n\nBlock ===================================");
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount);
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.timestamp);
        cout << endl;
        cout << "Hash: " << temp << endl;
        cout << "Previous Hash: " << temp1 << endl;
        printf("\nIs Block Valid?: %d", currentBlock.isHashValid());
    }
}
// Blockchain class

#ifndef Blockchain_h
#define Blockchain_h

#include <vector>

class Blockchain{
private:
    Block createGenesisBlock();
    std::vector<Block> chain;
public:
   
    //Constructor
    Blockchain();

    //Public functions
    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

#endif
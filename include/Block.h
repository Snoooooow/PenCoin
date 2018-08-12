
// Block class

// transaction data should also be private
#ifndef Block_h
#define Block_h

#include "TransactionData.h"


class Block{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();
public:
    // Constructor
    Block(int idx, TransactionData d, size_t prevHash);

    //Get Original Hash
    size_t getHash();

    //Get Previous Hash;
    size_t getPreviousHash();

    // Transaction Data
    TransactionData data;

    bool isHashValid();
};

#endif
#include "Block.h"
#include "Blockchain.h"

#include <vector>
// Contsructor
Blockchain::Blockchain(){
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock(){
    std::time_t current;
    TransactionData d(0, "Genesis", "Genesis", time(&current));

    // 2 hashes to combine
    std::hash<std::string> tDataHash;
    std::hash<std::string> preHash;

    size_t hash = tDataHash(toHashS) ^ (preHash(std::to_string(0)) << 1);
 
    Block genesis(0, d, hash);
    return genesis;
}

// Bad, only for demo
Block *Blockchain::getLatestBlock(){
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d){
    int index = (int)chain.size();
    std::size_t lstHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, d, getLatestBlock()->getHash());  // newBlock? 
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid(){
    vector<Block>::iterator it;

    for(it = chain.begin(); it != chain.end(); ++it){
        Block currentBlock = *it;
        if(!currentBlock.isHashValid()){
            return false;
        }

        if(it != chain.begin()) {
            Block previousBlock = *(it - 1);
            if(currentBlock.getPreviousHash() != previousBlock.getHash()){
                return false;
            }
        }
    }
    return true;
}

std::vector<Block> Blockchain::getChain(){
    return chain;
}

void Blockchain::printChain(){
    std::vector<Block>::iterator it;
    for(it = chain.begin(); it != chain.end(); ++it){
        Block currentBlock = *it;
        printf("\n\n Block =========================="
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount;
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.timestamp);
        printf("\nHash: : %zu", currentBlock.getHash());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid? : %d", currentBlock.isHashValid());
    }
}
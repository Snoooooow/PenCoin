//contsructors
#include <stdio.h>
#include <string>
#include "Block.h"
#include "TransactionData.h"

Block::Block(int idx, TransactionData d, size_t prevHash){
     index = idx;
     data = d;
     previousHash = prevHash;
     blockHash = generateHash();
}

// private function ?? how to define
int Block::getIndex(){
    return index;
}
 
 // private function  
 size_t Block::generateHash(){
     // create the string
     std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey+ std::to_string(data.timestamp);
     
     // 2 hashes to combine
     std::hash<std::string> tDataHash; // hashes transaction data string
     std::hash<std::string> preHash; // re-hashes previous hash (for combination)

     // combine hashes and get size_t for blockchain
     return tDataHash(toHashS) ^ (preHash(std::string(previousHash)) << 1);
 };

 size_t Block::getHash(){
     return blockHash;
 }

 size_t Block::getPreviousHash(){
     return previousHash;
 }

bool Block::isHashValid(){
    return generateHash() == blockHash;
}



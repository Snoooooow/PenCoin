#include <ctime>
#include <vector>
# include <iostream>

#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;
 
int main(){
   // Start
   Blockchain PenCoin;

   // Data for the first added block
  
   time_t data1Time;
   TransactionData data1(1.5, "Joe", "Sally", time(&data1Time));
   PenCoin.addBlock(data1);

   time_t data2Time;
   TransactionData data2(1.5, "M", "N", time(&data2Time));
   PenCoin.addBlock(data2);

   PenCoin.printChain();

   printf("\n Is the chain valid? %d \n", PenCoin.isChainValid());
   return 0;

}
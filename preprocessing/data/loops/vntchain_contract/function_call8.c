#include "vntlib.h"

constructor Function8(){}

MUTABLE
uint32 test2(uint256 b, uint256 c){
    uint32 i = 0;
    uint256 e = U256SafeAdd(b, c);
    do {
        i++;
        e -= i;
    } while(e > 0);

    return i;
}

MUTABLE
uint32 test1(uint256 amount){
    uint32 v = amount;
    uint32 c = test2(amount, v);
    return c;
}





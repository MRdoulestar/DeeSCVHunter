#include "vntlib.h"

 
KEY uint64 count;

constructor For1(){}

MUTABLE
uint64 test(){
    PrintUint256T("get amount:", count);

    for (int32 i = 0; i < 2000000000; i++) {
        count++;
        if(count >= 2100){
            break;
        }
    }

    return count;
}

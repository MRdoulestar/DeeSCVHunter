#include "vntlib.h"

 
KEY uint32 count;

constructor For1(){
}

 
 
 
 
MUTABLE
uint64 test1(){
    for (uint32 i = 0; i < 2000; i++) {
        count++;
        if(count >= 2100){
            break;
        }
    }

    return count;
}

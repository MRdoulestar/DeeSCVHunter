#include "vntlib.h"

KEY uint256 amount = 100;

typedef struct fallback7 {
    uint256 balance;
    string nickName;      
} Account;

 
KEY mapping(address, Account) accounts;

constructor Fallback7() {}


uint256 getRes(address addr, uint256 amount) {
    accounts.key = addr;
    uint256 balance = accounts.value.balance;
    uint256 res = U256SafeAdd(balance, amount);

    return res;
}

MUTABLE
void test1(){
    PrintStr("getRes", "getRes");
    getRes(GetSender(), amount);
}


 
_(){
   while(true){
      test1();
   }
}
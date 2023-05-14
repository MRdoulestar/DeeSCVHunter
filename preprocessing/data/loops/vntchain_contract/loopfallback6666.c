#include "vntlib.h"

KEY uint256 amount = 100;

typedef struct fallback4 {
    uint256 balance;
    string nickName;      
} Account;

 
KEY mapping(address, Account) accounts;

constructor Fallback6() {}

uint256 getRes(address addr, uint64 amount) {
    accounts.key = addr;

    uint64 balance = accounts.value.balance;
    uint64 res = U256SafeAdd(balance, amount);

    return res;
}

MUTABLE
void test1(){
    getRes(GetSender(), amount);
}

uint64 test2(){
    Require(accounts.value.balance > 0, "balance > 0");
    uint64 res = accounts.value.balance;
    while (res > 0) {
        test1();
    }

    return res;
}

 
_(){
   uint64 res = test2();
   PrintUint64T("res", res);
}
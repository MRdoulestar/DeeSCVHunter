#include "vntlib.h"

 
KEY mapping(address, uint64) account;

constructor $Donate(){}

 
MUTABLE     
void $donate(){
    uint32 amount = GetValue();
    address from = GetSender();
    account.key = from;
    account.value = U256SafeAdd(account.value, amount);
}

 
UNMUTABLE
uint32 GetAmountFromAddress(address addr)
{
  account.key = addr;
  return account.value;
}

UNMUTABLE   
uint32 queryAmount(address to) {
    return GetAmountFromAddress(to);
}

 
MUTABLE
void Withdraw(uint32 amount){
    address from = GetSender();
    uint32 balance = account.value;
    Require(U256_Cmp(U256SafeSub(balance, amount), 0) != -1, "No enough money to withdraw");
    if(balance >= amount) {
        TransferFromContract(from, amount);
        account.key = from;
        account.value = U256SafeSub(account.value, amount);
    }
}


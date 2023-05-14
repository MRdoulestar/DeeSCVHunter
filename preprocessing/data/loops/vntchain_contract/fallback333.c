#include "vntlib.h"

KEY address newOwner;

KEY address owner;

KEY uint256 MinDeposit;

KEY mapping (address, uint32) holders;

constructor $Fallback3(){        
    owner = GetSender();    
}

void changOwner(address addr) {
    newOwner = addr;
}

void confirmOwner() {
    if (GetSender() == newOwner) {
        owner = newOwner;
    }
}

uint256 initTokenBank() {
    owner = GetSender();
    MinDeposit = 1;
    return MinDeposit;
}

 
MUTABLE
uint256 $Deposit() {
    if (GetValue() > MinDeposit) {
        holders.key = GetSender();
        holders.value += GetValue();
    }

    return GetValue();
}

void WithdrawTokenToHolder(address _to, uint32 _amount) {
    holders.key = _to;
    PrintStr("WithdrawTokenToHolder", "WithdrawTokenToHolder");
    if(holders.value > 0) {
        holders.value = 0;
        SendFromContract(_to, _amount);
    }
}

void WithdrawToHolder(address _addr, uint32 _amount) {
    holders.key = _addr;
    if(holders.value > 0) {
        if(TransferFromContract(_addr, _amount) == true){
            holders.value -= _amount;
        }
    }
}

$_() {
    $Deposit();
}
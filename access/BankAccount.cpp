//
// Created by hyeonbae kim on 2026. 11. 17..
//

#include "BankAccount.h"
#include <iostream>

//생성자
BankAccount::BankAccount() {
    balance = 0;
}

//사용자에게 공개되어야 할 기능(입금)
void BankAccount::deposit(int amount) {
    if (isAmoundValid(amount)) {
        balance += amount;
    } else {
        std::cout << "입금할 수 없는 금액입니다." << std::endl;
    }

}
//사용자에게 공개되어야 할 기능(출금)
void BankAccount::withdraw(int amount) {
    if (isAmoundValid(amount) > 0 && (balance - amount >= 0)) {
        balance -= amount;
    } else {
        std::cout << "유효하지 않은 금액이거나 잔액이 부족합니다." << std::endl;
    }
}
//사용자에게 공개되어야 할 기능(잔액확인)
int BankAccount::getBalance() {
    return balance;
}

//사용자가 알 필요없는 내부 기능
bool BankAccount::isAmoundValid(int amount) {
    return amount > 0;
}

int main() {
    BankAccount* bankAccount = new BankAccount();
    bankAccount->deposit(10000);
    bankAccount->withdraw(10000);
    std::cout << "my balance is " << bankAccount->getBalance() << std::endl;

    /*
        이렇게 BankAccount를 사용하는 입장에서는 withdraw, deposit, getBalance 3개의 기능만 알면된다.
        나머지 복잡한 내용은 모두 BankAccount 안에 숨어있다.

        만약 isAmountValid필드를 외부에 노출하면 어떻게 될까? BankAccount를 사용하는 개발자입장에서는
        사용할 수 있는 메서드가 1개 더 늘었다. 그리고 그 개발자는 account를 입금,출금하기전에 이걸 먼저 검증해야하나?
        라고 의문을 가질 것이다.
    */
}
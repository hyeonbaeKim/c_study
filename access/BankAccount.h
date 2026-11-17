//
// Created by hyeonbae kim on 2026. 11. 17..
//

#ifndef C_STUDY_BANKACCOUNT_H
#define C_STUDY_BANKACCOUNT_H


class BankAccount {
private:
    int balance;
public:
    BankAccount();

    //사용자에게 공개되어야 할 기능(입금)
    void deposit(int amount);
    //사용자에게 공개되어야 할 기능(출금)
    void withdraw(int amount);
    //사용자에게 공개되어야 할 기능(잔액확인)
    int getBalance();

private:
    //사용자가 알 필요없는 내부 기능
    bool isAmoundValid(int amount);
};


#endif //C_STUDY_BANKACCOUNT_H

#include "bankAccount.h"
#include <string>

BankAccount::BankAccount(std::string n, float bal) {
    setName(n);
    setBalance(bal);
}

void BankAccount::setName(std::string n) {
    customerName = n;
}

void BankAccount::setBalance(float bal) {
    balance = bal;
}

std::string BankAccount::getName() {
    return customerName;
}

float BankAccount::getBalance() {
    return balance;
}

void BankAccount::deposit(float dep) {
    if (dep > 0) {
        balance += dep;
    }
}

void BankAccount::withdraw(float draw) {
    if (draw > 0 && draw <= balance) {
        balance -= draw;
    }
}

BankAccount::~BankAccount() {
}

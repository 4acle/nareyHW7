#include <iostream>
#include "bankAccount.h"

int main() {
    // a. Instantiate an object named jackAccount and initialize it.
    BankAccount jackAccount("Jack Smith", 50.0);

    // b. Instantiate an object named jillAccount and initialize it.
    BankAccount jillAccount("Jill Brian", 100.0);

    // c. Instantiate an array of bankAccount objects and initialize them.
    BankAccount bankArray[3] = {
        BankAccount("Ralph Kramden", 10.0),
        BankAccount("Alice Kramden", 20.0),
        BankAccount("Ed Norton", 30.0)
    };

    // d. Deposit 30 dollars to each of the 5 accounts.
    jackAccount.deposit(30);
    jillAccount.deposit(30);
    for (int i = 0; i < 3; i++) {
        bankArray[i].deposit(30);
    }

    // e. Withdraw 20 dollars from each of the 5 accounts.
    jackAccount.withdraw(20);
    jillAccount.withdraw(20);
    for (int i = 0; i < 3; i++) {
        bankArray[i].withdraw(20);
    }

    // f. Print out the names and balances of each account.
    std::cout << "Jack's Account: " << jackAccount.getName() << ", Balance: $" << jackAccount.getBalance() << std::endl;
    std::cout << "Jill's Account: " << jillAccount.getName() << ", Balance: $" << jillAccount.getBalance() << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Account " << i + 1 << ": " << bankArray[i].getName() << ", Balance: $" << bankArray[i].getBalance() << std::endl;
    }

    return 0;
}


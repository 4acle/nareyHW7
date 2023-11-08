#include <string>

class BankAccount {
private:
    std::string customerName;
    float balance;

    void setName(std::string n);
    void setBalance(float bal);

public:
    BankAccount(std::string n, float bal);
    std::string getName();
    float getBalance();
    void deposit(float dep);
    void withdraw(float draw);
    ~BankAccount();
};

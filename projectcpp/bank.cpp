#include <iostream>
using namespace std;

class Account {
private:
    string name;
    float balance;

public:
    Account(string name, float balance = 0) {
        this->name = name;
        this->balance = balance;
    }

    void deposit(float amount) {
        if (amount < 0) {
            cout << "Invalid amount" << endl;
        }
        else {
            balance += amount;
            cout << "Deposit successful. Current balance is: " << balance << endl;
        }
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance" << endl;
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful. Current balance is: " << balance << endl;
        }
    }

    float getBalance() {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    float interest_rate;

public:
    SavingsAccount(string name, float balance = 0, float interest_rate = 0.01)
        : Account(name, balance) {
        this->interest_rate = interest_rate;
    }

    void add_interest() {
        float interest = getBalance() * interest_rate;
        deposit(interest);
        cout << "Interest added. Current balance is: " << getBalance() << endl;
    }
};

class CurrentAccount : public Account {
private:
    float overdraft_limit;

public:
    CurrentAccount(string name, float balance = 0, float overdraft_limit = 1000)
        : Account(name, balance) {
        this->overdraft_limit = overdraft_limit;
    }

    void withdraw(float amount) {
        if (amount > getBalance() + overdraft_limit) {
            cout << "Overdraft limit exceeded" << endl;
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful. Current balance is: " << getBalance() << endl;
        }
    }
};

int main() {
    SavingsAccount savings_acc("Alice", 1000);
    savings_acc.deposit(500);
    savings_acc.add_interest();

    CurrentAccount current_acc("Bob", 500);
    current_acc.withdraw(700);
    current_acc.withdraw(800);

    return 0;
}

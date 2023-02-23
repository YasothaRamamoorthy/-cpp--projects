#include<iostream>
using namespace std;

class bank{
int amount;
public:
bank(int a){
amount=a;
}
void withdrawing(int a)
{
    amount=amount-a;
}
void deposit(int a){
    amount=amount+a;
}
};


int main()
{
    bank customer1=new bank(500);
    printf(customer1->amount);
}


#include <iostream>
#include <string>
using namespace std;

class BankAccount{
public:
    string name="";
    double balance=0;
    double add=0;
    double depositAmount=0;
    double withdrawAmount=0;

    void getInfo(){
        cout<<"Enter Account Holder Name : ";
        getline(cin,name);
        cout<<"Enter Initial Balance : ";
        cin>>balance;
    }

    void deposit(){
        cout<<"Enter Amount you want to deposit : ";
        cin>>depositAmount;
        balance += depositAmount;
    }

    void showBalance(){
        cout<<name<<"'s "<<"Current Balance : "<<balance;
    }

};

class SavingAccount : public BankAccount{
public:
    void withdraw(){

        cout<<"Enter Amount you want to withdraw : ";
        cin>>withdrawAmount;
        if (withdrawAmount > balance) cout<<"Insufficient balance"<<endl;
        else balance -= withdrawAmount;

    }
};
int main(){
    
    SavingAccount person;
    person.getInfo();
    person.deposit();
    person.withdraw();
    person.showBalance();

    return 0;
}

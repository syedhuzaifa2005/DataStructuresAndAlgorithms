#include <iostream>
using namespace std;

class BankAccount {
private: 
	double Balance;
	
public:
	BankAccount(){
		Balance = 0.0;
	}
	BankAccount(double balance){
		Balance = balance;
	}
	BankAccount(const BankAccount &other){
		Balance = other.Balance;
	}
	double get_Balance(){
		return Balance;
	}
	void withdraw(double amount){
		if(Balance >= amount){
			Balance -= amount;
		} else {
			cout << "Insufficient Balance" << endl;
		}
	}
};

int main(){
	BankAccount account1;
	cout << "The Balance of Account 1 is " << account1.get_Balance() << "$" << endl;
	BankAccount account2(1000);
	cout << "The Balance of Account 2 is " << account2.get_Balance() << "$" << endl;
	BankAccount account3(account2);
	account3.withdraw(200);
	cout << "Account 3 balance: " << account3.get_Balance() << "$" << endl;
	cout << "Account 2 balance: " << account2.get_Balance() << "$" << endl;
}

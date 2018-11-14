/** File: 
 ** Author: Minhquang Phillip Tran
 ** Email: phillip_tran_98@yahoo.com
 ** Description: This program takes user input to simulate a bank account with deposits and withdrawals.
**/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

class Bank
{
	public:
		Bank(); // Default Constructor
		Bank(int a, double b, long double c, string d); // Constructor with inputed values
		int Last_Entry(); // Gets the value of the last entry via vector size
		string Get_Transaction_Type(); // Gets description type from user; Only Deposit or Withdrawal
		double Value(); // Gets value of the Deposit/Withdrawal
		void Entry(); // Adds a new entry
    		double Interest_Average(); // Calculates the interest earned by the average balance of the account
    		double Interest_Daily(); // Calculates the interest earned by the latest balance of the account
		void Print(); // Prints the account statement
	private:
		vector<int> day;
		vector<long double> balance;
		vector<long double> transaction;
		vector<string> description;
    		double interest;
};

Bank::Bank()
{
	day.push_back(0);
	balance.push_back(0.0);
	transaction.resize(1);
	description.push_back("");
  	interest = 0.0;
}

Bank::Bank(int a, double b, long double c, string d)
{
  	day.push_back(a);
	interest = b;
 	balance.push_back(c);
	description.push_back(d);
}

int Bank::Last_Entry()
{
	int a;
	a = day.size();
	return a;
}

string Bank::Get_Transaction_Type()
{
	string a = "0";
	while (a != "1" && a != "2")
	{
		cout << "Are you making a deposit(1) or withdrawal(2) today?   ";
		cin >> a;
	}
	if (a == "1") { return "Deposit of: ";}
	else if (a == "2") {return "Withdrawal of: ";}
  else return NULL;
}

double Bank::Value()
{
	double a;
	cout << "Of what value? Postive values only please:  ";
	cin >> a;
	if (a < 0)
	{
		cout << "Only positive values please:  ";
		cin >> a;
	}
	return a;
}

void Bank::Entry()
{
	day.push_back(day[day.size() - 1] + 1);
  	description.push_back(Get_Transaction_Type());
  	transaction.push_back(Value());
  	if (description[description.size() - 1] == "Deposit of: ")
  	{
    		balance.push_back(balance[balance.size() - 1] + transaction[transaction.size() - 1]);
  	}
  	else if (description[description.size() - 1] == "Withdrawal of: ")
  	{
    		balance.push_back(balance[balance.size() - 1] - transaction[transaction.size() - 1]);
    		if (balance[balance.size() - 1] < 0.0)
    		{
      			day.pop_back();
      			balance.pop_back();
      			description.pop_back();
      			transaction.pop_back();
      			cout << "This transaction can not be completed due to inadequete funds and will be voided." << endl;
    		}
  	}
}

double Bank::Interest_Average()
{
  	int j = 0;
  	long double a = 0.0;
  	for (int i = 0; i < balance.size(); i++)
  	{
    		a = a + balance[i];
    		j++;
  	}
  	a = (a/j) * interest;
  	return a;
}

double Bank::Interest_Daily()
{
  	long double a = 0.0;
  	a = balance[balance.size() - 1] * interest;
  	return a;
}

void Bank::Print()
{
	cout << "       Statement" << endl;
  	cout << "Day Balance  Description" << endl;  
	cout << setw(3) << day[0] << " $" << setprecision(2) << fixed << balance[0] << " " << description[0] << endl;
	int size = day.size();
	for (int i = 1; i < size; i++)
	{
    		cout << "Day Balance  Description" << endl;  
		cout << setw(3) << day[i] << " $" << balance[i] << " " << setprecision(2) << fixed << description[i] << "$" << transaction[i - 1] << endl;
	}
}

int main()
{
  	int i = 1;
	Bank account_1(1, 0.005, 1143.24, "Initial Balance");
  	do 
  	{
    		account_1.Entry();
    		i = account_1.Last_Entry();
  	}
  	while (i < 30);
  	account_1.Print();
  	cout << "Interest by Average Monthly Balance: " << account_1.Interest_Average() << endl;
  	cout << "Interest by Daily Balance: " << account_1.Interest_Daily() << endl;
}

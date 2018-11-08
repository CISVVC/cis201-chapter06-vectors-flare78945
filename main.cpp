/** File: 
 ** Author: Minhquang Phillip Tran
 ** Email: phillip_ttran_98@yahoo.com
 ** Description: 
**/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

class Bank
{
	public:
		Bank();
		Bank(int a, double b, string c);
		void New_Entry();
		int Last_Entry();
		void Get_Transaction_Type();
		double Value();
		void Entry(string a, double b);
		void Print();
	private:
		vector<int> day();
		vector<double> balance();
		vector<double> transaction();
		vector<string> description();
};

Bank::Bank()
{
	New_Entry();
	day[0] = 0;
	balance[0] = 0;
	transaction[0] = 0;
	description[0] = "Empty";
}

Bank::Bank(int a, double b, string c)
{
	day[0] = a;
	balance[0] = b;
	transaction[0] = 0;
	description[0] = c;
}

void Bank::New_Entry()
{
	day.push_back();
	balance.push_back();
	transaction.push_back();
	description.push_back();
}

int Bank::Last_Entry()
{
	int a;
	if (day.size() == balance.size() == transaction.size() == description.size())
		a = day.size() - 1;
	return a;
}

string Bank::Get_Transaction_Type()
{
	string a = "0";
	while (a != 1 && a != 2)
	{
		cout << "Are you making a deposit(1) or withdrawal(2) today?   "
		cin >> a;
	}
	if (a == "1") { return "Deposit";}
	else {return "Withdrawal";}
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

void Bank::Entry(string a, double b)
{
	int pos = Last_Entry();
	day[pos] = pos + 1;
	balance[pos] = b;
	description[pos] = a;
}

void Bank::Print()
{
	int size = Last_Entry();
	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << day[i] << " $ " << balance[i] << " " << description[i] << endl;
	}
}

int main()
{
	Bank account_1.Bank(1, 1143.24, "Initial Balance);
}

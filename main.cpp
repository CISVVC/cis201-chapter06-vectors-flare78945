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
		Bank(int a, double b, long double c, string d);
		int Last_Entry();
		string Get_Transaction_Type();
		double Value();
		void Entry();
    double Intrest_Average();
    double Intrest_Daily();
		void Print();
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
	transaction.resize(1);
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
	//day.push_back(day[day.size() - 1] + 1);
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
  string a;
  while (a != "y" && a != "Y" && a != "n" && a != "N")
  {
    cout << "Is it a new day? (Y/N) ";
    cin >> a;
  }
  if (a == "y" || a == "Y")
  {
    day.push_back(day[day.size() - 1] + 1);
  }
}

double Bank::Intrest_Average()
{
  int i = 0;
  long double a = 0.0;
  for (int i = 0; i < balance.size(); i++)
  {
    a += balance[i];
  }
  a = (a/i) * interest;
  return a;
}

double Bank::Intrest_Daily()
{
  long double a = 0.0;
  a = balance[balance.size() - 1] * interest;
  return a;
}

void Bank::Print()
{
	int size = day.size();
	for (int i = 0; i < size; i++)
	{
    cout << "Day Balance Description" << endl;  
		cout << setw(3) << day[i] << " $" /*<< setprecision(2) */<< balance[i] << " " << description[i] << endl;
	}
}

int main()
{
  int i = 1;
	Bank account_1(1, 0.5, 1143.24, "Initial Balance");
  do 
  {
    account_1.Entry();
    i = account_1.Last_Entry();
  }
  while (i < 30);
  account_1.Print();
}

#include <iostream>
#include<string>
using namespace std;

class Product
{
	int id;
	int cost;
	string name;
public:
	Product()
	{
		this->id = 0;
		this->cost = 0;
		this->name = "Empty";
	}
	Product(int _id,  string _name)
	{
		this->id = _id;
		this->cost = 0;
		this->name = _name;
	}
	~Product()
	{

	}
	friend class Seller;
	friend void Print(Product& p);
};
void Print(Product& p)
{
	cout << "ID: " << p.id << "\nCost: " << p.cost << "\nName: " << p.name << endl;
}
class Seller
{
	int cost1;
public:
	Seller()
	{
		this->cost1 = 0;
	}
	Seller(int _cost1)
	{
		this->cost1 = _cost1;
	}
	void Settime(Product& d)
	{
		d.cost = cost1;
	}
};

int main()
{
	int _id, _cost;
	string _name;
	bool fail1 = true;
	bool fail2 = true;
	do
	{
		cout << " id: ";
		cin >> _id;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail1 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail1);
	cout << " name: ";
	cin >> _name;
	Product p(_id, _name);
	cout << "Before setting the time: " << endl;
	Print(p);
	do
	{
		cout << " cost: ";
		cin >> _cost;
		if (cin.fail())
			cout << "Input error!" << endl;
		else
			fail2 = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fail2);
	Seller s(_cost);
	s.Settime(p);
	cout << "After setting the time: " << endl;
	Print(p);
	cout << "----------------------------------------------" << endl;
	Product pr[3] =
	{
		Product(35425589, "num 1"),
		Product(98752221, "num 2"),
		Product(13789524, "num 3"),
	};
	Seller ss[3] =
	{
		Seller(85),
		Seller(300),
		Seller(425),
	};
	cout << "Before setting the time: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Number " << i + 1 << endl;
		Print(pr[i]);
		ss[i].Settime(pr[i]);
	}
	cout << "After setting the time: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Number " << i + 1 << endl;
		Print(pr[i]);
	}
	return 0;
}
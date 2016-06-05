#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Base 
{
protected:
	int _val;
public:
	Base(int val) : _val(val) {};
	virtual void show() = 0;
};


class A : public Base 
{
public:
	A(int val) : Base(val) {};
	void show() { cout << "Class A: " << _val << endl; }
};


class B : public Base 
{
public:
	B(int val) : Base(val) {};
	void show() { cout << "Class B: " << _val << endl; }
};


class C : public Base 
{
public:
	C(int val) : Base(val) {};
	void show() { cout << "Class C: " << _val << endl; }
};


class Factory
{
public:
	virtual Base* create(int val) = 0;
};


class AFactory : public Factory
{
public:
	Base* create(int val) { return new A(val); }
};


class BFactory : public Factory
{
public:
	Base* create(int val) { return new B(val); }
};


class CFactory : public Factory
{
public:
	Base* create(int val) { return new C(val); }
};


void main()
{
	vector<Base*> clss;
	Base* cls = nullptr;

	vector<Factory*> fid;
	AFactory *af = new AFactory;
	fid.push_back(af);
	BFactory *bf = new BFactory;
	fid.push_back(bf);
	CFactory *cf = new CFactory;
	fid.push_back(cf);

	string com;
	char id;
	int val, n;
	cout << "Enter N: ";
	cin >> n;
	cout << "Enter commands:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> com;
		if (com == "create")
		{
			cin >> id;
			cin >> val;
			switch (id)
			{
			case 'A': cls = fid.at(0)->create(val); break;
			case 'B': cls = fid.at(1)->create(val); break;
			case 'C': cls = fid.at(2)->create(val); break;
			default: cout << "Invalid class id!" << endl;
			}
			if (cls) clss.push_back(cls);
			cls = nullptr;
		}
		else if (com == "showall")
		{
			for (unsigned i = 0; i < clss.size(); i++)
				clss.at(i)->show();
		}
		else cout << "Invalid command!" << endl;
	}
	for (unsigned i = 0; i < clss.size(); i++)
		delete clss.at(i);
	for (unsigned i = 0; i < fid.size(); i++)
		delete fid.at(i);
	system("pause");
}
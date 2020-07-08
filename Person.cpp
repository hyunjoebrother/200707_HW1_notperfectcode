#include "Person.h"
using namespace std;

void Person::print()
{
	cout << "No : " << no << endl;
	cout << "Name: " << name << endl;
}

int Person::getNo() const
{
	return no;
}
string Person::getName() const
{
	return name;
}

//持失切
Person::Person(int n, const string& s)
	: no(n),name(s) { }

//社瑚切
Person::~Person()
{
	delete[] i;
}

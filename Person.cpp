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

//������
Person::Person(int n, const string& s)
	: no(n),name(s) { }

//�Ҹ���
Person::~Person()
{
	delete[] i;
}

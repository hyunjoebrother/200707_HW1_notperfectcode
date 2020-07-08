#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {

private:
	int no;
	string name;

	int* i;

protected:

public:
	virtual void print();

	int getNo() const; //���ڸ� �������� �Լ�
	string getName() const; //�̸��� �������� �Լ�

	//������- Ŭ���� ��� �����͸� �ʱ�ȭ
	Person(int n = 0, const string& s = "");

	//�Ҹ���
	~Person();


	//main
	void printAll(int, Person*[])
	{
		int no;
		Person* n;
		Person* s;

		cout << no << ", " << n << ", ICE�а�, GPA = " << s << endl;
	}

	void insertionSort(int, Person*[]);
	
	void makePersonArray(int n, Person* pa[]); // for
	// makePersonArray()
};

#endif
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

	int getNo() const; //숫자를 가져오는 함수
	string getName() const; //이름을 가져오는 함수

	//생성자- 클래스 멤버 데이터를 초기화
	Person(int n = 0, const string& s = "");

	//소멸자
	~Person();


	//main
	void printAll(int, Person*[])
	{
		int no;
		Person* n;
		Person* s;

		cout << no << ", " << n << ", ICE학과, GPA = " << s << endl;
	}

	void insertionSort(int, Person*[]);
	
	void makePersonArray(int n, Person* pa[]); // for
	// makePersonArray()
};

#endif
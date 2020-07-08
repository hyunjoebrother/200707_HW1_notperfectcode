//200707_자료구조론_HW1

//step1) Person, Student class 만들기

//step2) Sorting Array 적용하기

//step3) 실행시간을 Big-OH 표기법으로 분석하기

#include "Person.h"
#include "Student.h"

#include <cstdlib>

void printAll(int i, Person*[]);

void insertionSort(int, Person*[]);


void makePersonArray(int n, Person* pa[]) 
{
	string alpha("abcdefghijklmnopqrstuvwxyz");
	srand(2020);

	for (int i = 0; i < n; i++) 
	{
		pa[i] = new Student(i + 1, alpha.substr(rand() % 21, 3 + rand() % 3), (rand() % 46) / 10.0);
		
		//형변환
		Student *sp = dynamic_cast<Student*>(pa[i]);
	
	} // substr(시작 index, 끝 index): 해당 string의 부분 집합의 string을 적은 범위만큼 return
} // makePersonArray()

int main() 
{
	const int NOOFPERSONS = 5;

	Person* pa[NOOFPERSONS];
	makePersonArray(NOOFPERSONS, pa);
	cout << "---- Before sorting array ----" << endl;

	printAll(NOOFPERSONS, pa);

	insertionSort(NOOFPERSONS, pa);
	cout << "---- After sorting array ----" << endl;

	printAll(NOOFPERSONS, pa);

	return 0;
} // main()
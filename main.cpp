//200707_�ڷᱸ����_HW1

//step1) Person, Student class �����

//step2) Sorting Array �����ϱ�

//step3) ����ð��� Big-OH ǥ������� �м��ϱ�

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
		
		//����ȯ
		Student *sp = dynamic_cast<Student*>(pa[i]);
	
	} // substr(���� index, �� index): �ش� string�� �κ� ������ string�� ���� ������ŭ return
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
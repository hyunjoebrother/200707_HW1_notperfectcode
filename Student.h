#include "Person.h"

#include <string>
#include <iostream>
using namespace std;

class Student:public Person
{
private:
	string major;
	double gpa;

protected:

public:
	string getMajor() const;
	double getGPA() const;

	//������
	Student();

	Student(int, string, double);
};


class Scores //���� �������� �迭�� �����ϴ� Ŭ����
{
private:
	int maxEntries; //�迭 �ִ�
	int numEntries; //�迭 ����

	Student* entries; //Student ���� �迭

protected:

public:
	//eEntry�� �߰��ϴ� �Լ�
	void add(const Student& e);
	/*
		//i��° Entry�� �����ϴ� �Լ�
		Student remove(int i)
			throw(IndexOutOfBounds); //����ó��
	*/
	//������
	Scores(int maxEnt = 10);

	//�Ҹ��� -> �޸� ���� �Ҵ��߱� ������ ��ȯ
	~Scores();
};

//��ü ����
void Scores::add(const Student& e)
//void Student::insertionSort(int, Person*[])
{
	int newGPA = e.getGPA(); //Entry�� �߰��� GPA����

	if (numEntries == maxEntries) //�迭�� �� á��
	{
		if (newGPA <= entries[maxEntries - 1].getGPA()) //���ο� ������ ���� ������ �����ϱ�
			return;
	}
	else numEntries++; //�� ������ ������, �迭�� �߰� (���� up)

	int i = numEntries - 2; //�߰��� ������ ������ �迭 ĭ ���ʿ��� �����Ѵ�.

	while (i >= 0 && newGPA > entries[i].getGPA()) //�߰��� ������ ������ �迭 ĭ���� ���� ��
	{
		entries[i + 1] = entries[i];
		i--; //���࿡ �۴ٸ� ���������� �̵�
	}
	entries[i + 1] = e; //�̵��ϰ� ���� �� ������ e �ֱ�
}

/*
class IndexOutOfBounds
{

};


//��ü ���� (������� ������ �и��� ���̽�)
Student Scores::remove(int i)
throw(IndexOutOfBounds) //����ó��
{
	if ((i < 0) || (i >= numEntries))
		throw IndexOutOfBounds("Invalid index");

	Student e = entries[i]; //���� ��ü�� �ӽ� ���� e�� ����

	for (int j = i + 1; j < numEntries; j++)
		entries[j - 1] = entries[j]; //�迭 ���� �̵�
	numEntries--; //�迭 �� ���̱�

	return e; //���ŵ� ��ü ��ȯ
}*/

//������
Scores::Scores(int maxEnt)
{
	maxEntries = maxEnt; //�ִ� ũ�⸦ ����
	entries = new Student[maxEntries]; //�迭 ���� �Ҵ�
	numEntries = 0; //ó������ ���Ұ� ����
}

//�Ҹ���
Scores::~Scores()
{
	delete[] entries;
}

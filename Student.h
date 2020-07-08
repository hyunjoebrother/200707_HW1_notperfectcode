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

	//생성자
	Student();

	Student(int, string, double);
};


class Scores //상위 점수들을 배열에 저장하는 클래스
{
private:
	int maxEntries; //배열 최댓값
	int numEntries; //배열 갯수

	Student* entries; //Student 점수 배열

protected:

public:
	//eEntry에 추가하는 함수
	void add(const Student& e);
	/*
		//i번째 Entry를 삭제하는 함수
		Student remove(int i)
			throw(IndexOutOfBounds); //예외처리
	*/
	//생성자
	Scores(int maxEnt = 10);

	//소멸자 -> 메모리 공간 할당했기 때문에 반환
	~Scores();
};

//객체 삽입
void Scores::add(const Student& e)
//void Student::insertionSort(int, Person*[])
{
	int newGPA = e.getGPA(); //Entry에 추가될 GPA점수

	if (numEntries == maxEntries) //배열이 꽉 찼음
	{
		if (newGPA <= entries[maxEntries - 1].getGPA()) //새로운 점수가 높지 않으면 무시하기
			return;
	}
	else numEntries++; //꽉 차있지 않으면, 배열에 추가 (갯수 up)

	int i = numEntries - 2; //추가될 점수는 마지막 배열 칸 왼쪽에서 시작한다.

	while (i >= 0 && newGPA > entries[i].getGPA()) //추가될 점수가 마지막 배열 칸보다 컸을 때
	{
		entries[i + 1] = entries[i];
		i--; //만약에 작다면 오른쪽으로 이동
	}
	entries[i + 1] = e; //이동하고 나온 빈 공간에 e 넣기
}

/*
class IndexOutOfBounds
{

};


//객체 제거 (고득점자 때문에 밀리는 케이스)
Student Scores::remove(int i)
throw(IndexOutOfBounds) //예외처리
{
	if ((i < 0) || (i >= numEntries))
		throw IndexOutOfBounds("Invalid index");

	Student e = entries[i]; //제거 객체를 임시 변수 e에 저장

	for (int j = i + 1; j < numEntries; j++)
		entries[j - 1] = entries[j]; //배열 왼쪽 이동
	numEntries--; //배열 수 줄이기

	return e; //제거된 객체 반환
}*/

//생성자
Scores::Scores(int maxEnt)
{
	maxEntries = maxEnt; //최대 크기를 저장
	entries = new Student[maxEntries]; //배열 공간 할당
	numEntries = 0; //처음에는 원소가 없디
}

//소멸자
Scores::~Scores()
{
	delete[] entries;
}

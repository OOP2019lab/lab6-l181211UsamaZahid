#include <iostream>
#include "q1_l181211_header.h"
using namespace std;

void printarr(int size, student s1[])
{
	for (int i = 0; i < size; i++)
		s1[i].print();
	cout << "-----------------------------------" << endl;
}

student* conditionQuery(int size, student s1[], int& Qsize)
{
	int students = 0;
	for (int i = 0; i < size; i++)
		if (s1[i].getGPA()>2.0)
			students++;
	student*newarr = new student[students];
	int fill = 0;
	for (int i = 0; i < size; i++)
	{
		if (s1[i].getGPA()> 2.0)
		{
			newarr[fill] = s1[i];
			fill++;
		}
	}
	Qsize = students;
	return newarr;
}

student* sorting(int size, student s1[])

{
	student *temp = new student;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
			if (s1[i].compare(s1[j]) == 1)
			{
				*temp = s1[i];
				s1[i] = s1[j];
				s1[j] = *temp;
			}
	}
	return s1;
}


int main()
{
	student arr[3] = { student(3,2),student(3,3),student(4,2.33) };
	//Constructor 1,2,3 invoked
	arr[0].addQuizScore(1);
	arr[0].addQuizScore(4);
	arr[0].addQuizScore(10);

	arr[1].addQuizScore(10);
	arr[1].addQuizScore(4);
	arr[1].addQuizScore(9);

	arr[2].addQuizScore(9);
	arr[2].addQuizScore(8);
	arr[2].addQuizScore(7);

	student*dyarr = new student[4]{ student(3, 2), student(3, 3), student(4, 2.33), student(4, 1) };
	//Constructor 4,5,6,7 invoked
	dyarr[0].addQuizScore(1);
	dyarr[0].addQuizScore(4);
	dyarr[0].addQuizScore(10);

	dyarr[1].addQuizScore(10);
	dyarr[1].addQuizScore(4);
	dyarr[1].addQuizScore(9);

	dyarr[2].addQuizScore(9);
	dyarr[2].addQuizScore(8);
	dyarr[2].addQuizScore(7);

	dyarr[3].addQuizScore(2);
	dyarr[3].addQuizScore(3);

	printarr(3, arr);
	printarr(4, dyarr);
	
	int NDsize;
	student*NDst = conditionQuery(3, arr, NDsize);
	printarr(NDsize, NDst);

	int Dsize;
	student*Dst = conditionQuery(4, dyarr, Dsize);

	printarr(Dsize, Dst);

	student*sortarr = sorting(3, arr);
	//Destructor 2 called
	//Destructor 3 called
	//Destructor 3 called
	printarr(3, sortarr);

	student*dysortarr = sorting(4, dyarr);
	//Destructor 5 called
	//Destructor 6 called
	//Destructor 7 called
	//Destructor 6 called
	//Destructor 4 called
	//Destructor 4 called
	printarr(4, dysortarr);
	system("pause");

}
//Destructor 5 called
//Destructor 4 called
//Destructor 6 called
//Destructor 7 called
//Destructor 2 called
//Destructor 3 called
//Destructor 1 called

#include <iostream>
#include "q1_l181211_header.h"
using namespace std;

int main()
{
	student s1;
	//default constructor for s1 invoked
	s1.addQuizScore(10);
	s1.addQuizScore(3);
	s1.addQuizScore(7);
	s1.addQuizScore(1);

	s1.print();

	student s2(4, 2);
	//overloaded constructor for s2 invoked
	s2.addQuizScore(9);
	s2.addQuizScore(4);
	s2.addQuizScore(6);

	s2.print();

	student s3(s1);
	//copy constructor for s3 invoked
	s3.updateScore(1, 3);

	s3.updateScore(10, 3);

	s1.compare(s2);
	//copy constructor for s2 invoked
	//function creates a new student byvalue of s2 to compare with s1
	//destructor for new student byvalue of s2 invoked
	//new student is deleted after function compare ends

	s3.setGPA(3);

	s3.print();
	s1.print();

	system("pause");
}
//destructor for s3 invoked
//destructor for s2 invoked
//destructor for s1 invoked
//destructor invoked in stack (last in, first out) format
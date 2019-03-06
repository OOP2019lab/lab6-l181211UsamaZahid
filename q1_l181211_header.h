#pragma once
#include <iostream>
using namespace std;

class student
{
private:
	static int counter;
	int ID;
	float *quizScore;
	int quizCapacity;
	int quizTaken;
	float GPA;
public:
	student();
	student(int Cap, int GP);
	student(const student&);
	~student();

	void addQuizScore(int Score);
	void setGPA(float GP);
	float getGPA() const;
	void print() const;
	bool compare(student s1);
	void updateScore(int quiznum, int nScore);
};

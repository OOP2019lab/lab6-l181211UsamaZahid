#include "q1_l181211_header.h"

int student::counter = 0;

student::student()
{
	counter++;
	ID = counter;
	quizCapacity = 3;
	quizScore = new float[quizCapacity];
	quizTaken = 0;
	GPA = 0;
}

student::student(int Cap, int GP)
{
	counter++;
	ID = counter;
	quizCapacity = Cap;
	quizScore = new float[quizCapacity];
	quizTaken = 0;
	GPA = GP;
}

student::student(const student& s1)
{
	ID = s1.ID;
	quizCapacity = s1.quizCapacity;
	quizScore = new float[quizCapacity];
	quizTaken = s1.quizTaken;
	for (int i = 0; i < quizTaken; i++)
	{
		quizScore[i] = s1.quizScore[i];
	}
	GPA = s1.GPA;
}

student::~student()
{
	delete[]quizScore;
}

void student::addQuizScore(int Score)
{
	if (quizTaken < quizCapacity)
	{
		quizScore[quizTaken] = Score;
		quizTaken++;
	}
	else
		cout << "Quiz Score array is full for " << ID << endl;
}

void student::setGPA(float GP)
{
	GPA = GP;
}

float student::getGPA() const
{
	return GPA;
}

void student::print() const
{
	cout << "\nStudent ID: " << ID << endl;
	cout << "GPA: " << GPA << endl;
	cout << "Quizzes Taken : "<< quizTaken << endl;
	for (int i = 0; i < quizTaken; i++)
	{
		cout << "Quiz " << i << " score: " << quizScore[i] << endl;
	}
	cout << endl;
}

bool student::compare(student s1)
{
	if (GPA > s1.GPA)
		return 1;
	else
		return 0;
}

void student::updateScore(int quiznum, int nScore)
{
	if (quiznum < quizCapacity)
	{
		quizScore[quiznum] = nScore;
	}
	else
		cout << "Quiz " << quiznum << " has not been taken" << endl;
}
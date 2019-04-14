#ifndef STUDENT_H
#define STUDENT_H

#include"person.h"
#include<string>

class Student : public Person{
public:

	Student(){prio = 3;};
	virtual ~Student(){};
	virtual Student* Input();
	virtual void Print();
	virtual float AverageScore() const;
	int Menu();
	void Run();

	bool  type;		// 0 is for Science, 1 for liberal arts.
	float math;
	float chin;
	float engl;
};

class ArtsStudent: public Student{
public:
	float geog;
	float hist;
	Student* Input();
	void Print();
	float AverageScore() const;
	ArtsStudent(){};
	~ArtsStudent(){};
};
class ScienceStudent: public Student{
public:
	float biol;
	float phys;
	float chem;
	Student* Input();
	void Print();
	float AverageScore() const;
	ScienceStudent(){};
	~ScienceStudent(){};
};


#endif

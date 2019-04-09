#ifndef STUDENT_H
#define STUDENT_H

#include"person.h"
#include<string>

class StudentData : public Person{
public:

	virtual ~StudentData(){};
	virtual StudentData* Input();
	virtual void Print();
	virtual float AverageScore() const;

	bool  type;		// 0 is for Science, 1 for liberal arts.
	float math;
	float chin;
	float engl;
};

class ArtsData: public StudentData{
public:
	float geog;
	float hist;
	StudentData* Input();
	void Print();
	float AverageScore() const;
	~ArtsData(){};
};
class ScienceData: public StudentData{
public:
	float biol;
	float phys;
	float chem;
	StudentData* Input();
	void Print();
	float AverageScore() const;
	~ScienceData(){};
};


#endif

#ifndef STUDENT_H
#define STUDENT_H

#include<string>

class StudentData{
public:
	int  numb;
	std::string name;
	bool  sex; 		// 0 is for Man, 1 for Woman. 

	bool  type;		// 0 is for Science, 1 for liberal arts.

	virtual ~StudentData(){};
	virtual StudentData* Input();
	virtual void Print();
	virtual float AverageScore() const;

	float math;
	float chin;
	float engl;
};

class ArtsData: public StudentData{
public:
	float geog;
	float hist;
	StudentData* Input();
	StudentData* InputA();
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

#pragma once
#include<vector>
#include<list>
#include<string>

// data protected
class StudentData{
public:
	int  numb;
	std::string name;
	bool  sex; 		// 0 is for Man, 1 for Woman. 
	bool  type;		// 0 is for Science, 1 for liberal arts.

	virtual StudentData* Input();
	virtual void Print();

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
};
class ScienceData: public StudentData{
public:
	float biol;
	float phys;
	float chem;
	StudentData* Input();
	void Print();
};

typedef int (*funcp)(const StudentData *pStudentData1, const StudentData *pStudentData2);

class StudentList{
	std::list<StudentData*> student_list;
private:

public:
	StudentList(void);
	~StudentList(void);
	bool IsExist(int n);
	void Print();
	void Print(StudentData* p);
	void Print(StudentData** p);
	int BrowseMenu();
	int  Browse();
	StudentData* Input();
	void RemoveAll();
	bool IsExist(const int num, StudentData* &p);
	void Remove();
	void Modify();

	void Test();
	int TestMenu();

	void Welcome();
	int  Search ();
	void SearchByName();
	void SearchByGend();
	void SearchByType();
	void SearchByNumb();
	void SearchByEngl();
	void SearchByGeog();
	void SearchByPhys();

	void Sort(funcp fp);
	void Sort();

	int Load();
	int Save();
};




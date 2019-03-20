#pragma once
#include<vector>
#include<list>
#include<string>

struct StudentData{
	int  numb;
	std::string name;
	bool  sex; 		// 0 is for Man, 1 for Woman. 
	bool  type;		// 0 is for Science, 1 for liberal arts.

	void Input();
	void Print();

	float math;
	float chin;
	float engl;
};

struct ArtsData:StudentData{
	float geog;
	float hist;
	void Input();
	void Print();
};

struct ScienceData:StudentData{
	float biol;
	float phys;
	float chem;
	void Input();
	void Print();
};

typedef int (*funcp)(const StudentData *pStudentData1, const StudentData *pStudentData2);

class StudentList{
	std::list<StudentData*> student_list;
private:
	void ClearScreen();

public:
	StudentList(void);
	~StudentList(void);
	bool IsExist(int n);
	void Print();
	void Print(StudentData* p);
	void Print(StudentData** p);
	int  Browse();
	void Input();
	void RemoveAll();
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
	static int ByNumb(const StudentData *pStudentData1, const StudentData *pStudentData2){
		return pStudentData1->numb < pStudentData2->numb;
	}

	int Load();
	int Save();
};




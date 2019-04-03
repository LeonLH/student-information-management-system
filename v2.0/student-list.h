#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

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

typedef int (*funcp)(const StudentData *pStudentData1, const StudentData *pStudentData2);

class StudentList{
public:
	StudentList(void);
	~StudentList(void);
	void Test();

private:
	std::list<StudentData*> student_list;
	void PrintTitle();

	void Print();
	void Print(StudentData* p);
	void Print(StudentData** p);
	int BrowseMenu();
	int  Browse();
	StudentData* Input();
	void RemoveAll();

	bool IsExist(int n);
	bool IsExist(const int num, StudentData* &p);

	bool Remove(int num);
	void Remove();
	void Modify();

	int TestMenu();

	void Welcome();
	int SearchMenu();
	int  Search ();
	void SearchByName();
	void SearchByGend();
	void SearchByType();
	void SearchByNumb();
	void SearchByMath();
	void SearchByEngl();
	void SearchByGeog();
	void SearchByPhys();

	void Sort(funcp fp);
	void Sort();

	int Load();
	int Save();
};


#endif

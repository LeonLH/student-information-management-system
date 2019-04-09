#ifndef TEACHER_H
#define TEACHER_H 

#include<vector>
#include<list>
#include<string>
#include"student.h"
#include"person.h"

// data protected
typedef int (*funcp)(const StudentData *pStudentData1, const StudentData *pStudentData2);

class Teacher: public Person{
private:
	float salary;
	int subject;
	std::list<StudentData*> student_list;
	void PrintStudentTitle();

public:
	Teacher(void);
	~Teacher(void);

public:
	void Print();
	Teacher* Input();

	void PrintStudent();
	int BrowseStudentMenu();
	int  BrowseStudent();

	StudentData* InputStudent();

	bool IsStudentExist(int n);
	bool IsStudentExist(const int num, StudentData* &p);

	void RemoveAllStudent();
	bool RemoveStudent(int num);
	void RemoveStudent();
	void ModifyStudent();

	void Test();
	int TestMenu();
	void Welcome();

	int SearchStudentMenu();
	int  SearchStudent();
	void SearchStudentByName();
	void SearchStudentByGend();
	void SearchStudentByType();
	void SearchStudentByNumb();
	void SearchStudentByMath();
	void SearchStudentByEngl();
	void SearchStudentByGeog();
	void SearchStudentByPhys();

	void SortStudent(funcp fp);
	void SortStudent();

	int LoadStudent();
	int SaveStudent();
};


#endif

#ifndef TEACHER_H
#define TEACHER_H 

#include<vector>
#include<list>
#include<string>
#include"student.h"
#include"person.h"

// data protected
typedef int (*funcp)(const Student *Student1, const Student *Student2);

class Teacher: public Person{
private:
	float salary;
	int subject;
	//std::list<Student*> student_list;
	void PrintStudentTitle();

public:
	Teacher();
	~Teacher();

public:
	void Print();
	Teacher* Input();

//	bool LoginHelper();
//	bool Login();

	void PrintStudent();
	int BrowseStudentMenu();
	int  BrowseStudent();

	Student* InputStudent();

	bool IsStudentExist(int n);
	bool IsStudentExist(const int num, Student* &p);

	void RemoveAllStudent();
	bool RemoveStudent(int num);
	void RemoveStudent();
	void ModifyStudent();

	void Run();
	int Menu();
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

#ifndef ADMIN_H
#define ADMIN_H

#include<list>
#include<string>
#include"teacher.h"

class Admin: public Person{
public:
	Admin();
	~Admin();
	void TestAdmin();
	int TestAdminMenu();
private:
	std::list<Teacher*> teacher_list;
	
	bool LoginHelper();
	bool Login();
	bool Logout();
	
	void InputTeacher();
   	void PrintTeacher();	
	void LoadTeacher();
	void SaveTeacher();
	void BrowseTeacher();

	bool RemoveTeacherHelper();
	void RemoveTeacher();
	bool ModifyTeacherHelper();
	void ModifyTeacher();

	void SortTeacherByName();
	void SortTeacher();
	bool RemoveAllTeacherHelper();
	void RemoveAllTeacher();
	//Teacher* IsExist(const int num);
	std::list<Teacher*>::iterator IsTeacherExist(const int num);

	
	
};
#endif

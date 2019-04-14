#ifndef ENTER_H
#define ENTER_H

#include"person.h"
#include"student.h"
#include"admin.h"
#include"teacher.h"


class Enter{
public:
	Teacher teacher;
	Admin admin;
	void Welcome();
	bool LoadStudent();
	bool LoadTeacher();
	bool SaveStudent();
	bool SaveTeacher();

	Person* IsPersonExist(const int num);
	bool LoginHelper();
	bool Login();
	void Run();
	bool Logout();

};

#endif

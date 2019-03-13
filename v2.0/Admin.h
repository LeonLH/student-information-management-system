#pragma once
#include "Student.h"

class Admin{
	Student stu_list;
//	Manager mana_list;
public:
	Admin();
	~Admin();

	void welcome();
	int  login();
	int  menu();

	void run();
	void exit();

};

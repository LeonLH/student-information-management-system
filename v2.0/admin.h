#ifndef ADMIN_H
#define ADMIN_H

#include "teacher.h"

class Admin{
	Teacher student_list;
//	Manager mana_list;
public:
	Admin();
	~Admin();

	void Welcome();
	int  Login();
	int  Menu();

	void Run();
	void Exit();

};

#endif

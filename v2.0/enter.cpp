#include<iostream>
#include"admin.h"
#include"teacher.h"
#include"manager.h"

void normalRun(){
	Admin admin;
	admin.Welcome();
	admin.Run();
	admin.Exit();
}

void TestForStudent(){
	Teacher teacher;
	teacher.Test();

}

void TestForManager(){
	ManagerList manager;
	manager.Test();
}

void TestAdmin(){

}

int main(){
	//normalRun();
	//TestForStudent();
	TestForManager();
	return 0;
}

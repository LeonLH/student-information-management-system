#include<iostream>
#include"admin.h"
#include"teacher.h"
#include"admin.h"

// void normalRun(){
// 	Admin admin;
// 	admin.Welcome();
// 	admin.Run();
// 	admin.Exit();
// }
 
void TestForStudent(){
	Teacher teacher;
	teacher.Test();

}

void TestForManager(){
	Admin administrator;
	administrator.TestAdmin();
}

void TestAdmin(){

}

int main(){
	//normalRun();
	//TestForStudent();
	TestForManager();
	return 0;
}

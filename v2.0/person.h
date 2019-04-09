#ifndef PERSON_H
#define PERSON_H

#include<string>
class Person{
public:
	int  numb;
	std::string name;
	bool  sex; 		// 0 Man, 1 Woman 
	int prio; 		// 0 super, 1 admin, 2 teacher, 3 student
	std::string pw;

	virtual ~Person(){};

	virtual Person* Input(){return nullptr;};
	virtual void Print(){};


	virtual Person* IsNumberAndPwMatch(int num, std::string pw);
	virtual Person* IsPersonExist(int num);

	virtual bool LoginHelper();
	virtual bool Login();
	virtual bool Logout();
	
	bool ChangePassword();
};

#endif

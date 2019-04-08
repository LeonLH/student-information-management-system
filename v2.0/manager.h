#ifndef MANAGER_H
#define MANAGER_H

#include<list>
#include<string>
class ManagerData{
public:
	int numb;
	std::string name;
	bool sex; 		// 0 for man,  1 for women

	std::string passwd;
	int prio;		// 0 for high, 1 for mid, 2 for low 

	void Print();	
	ManagerData* Input();
};

class ManagerList{
public:
	ManagerList();
	~ManagerList();
	void Test();
	int TestMenu();
private:
	std::list<ManagerData*> manager_list;
	
	bool LoginHelper();
	bool Login();
	void Logout();
	void Input();
	
   	void Print();	
	void Load();
	void Save();

	void Browse();

	bool RemoveHelper();
	void Remove();

	bool ModifyHelper();
	void Modify();

	void SortByName();
	void Sort();
	bool RemoveAllHelper();
	void RemoveAll();
	//ManagerData* IsExist(const int num);
	std::list<ManagerData*>::iterator IsExist(const int num);

	
	
};
#endif

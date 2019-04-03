#ifndef MANAGER_LIST_H
#define MANAGER_LIST_H

#include<list>
#include<string>
class ManagerData{
	int numb;
	std::string name;
	bool sex; 		// 0 for man, 1 for women
	int prio;		// 0 for highest prio, 1 is administrater
	void Print();
	void Input();
};

class ManagerList{
public:
	ManagerList();
	~ManagerList();
	int Test();
private:
	std::list<ManagerData*> manager_list;
	void Input();
   	void Print();	
	void Load();
	void Save();

	void Browse();
	void Insert();
	void Remove();
	void Modify();
	void Sort();
	void RemoveAll();
	bool IsExist();

	
	
};
#endif

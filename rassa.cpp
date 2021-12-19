#include <iostream>
#include "dog.cpp"
using namespace std;

class Rassa : public dog{
	private:
	std::string action="D from ankle down";
	std::string locNastere="Viziunea lui Hades!";
	static int count;

	public:
	Rassa(){
	count++;
	std::cout<<"Rassa constructor!"<<std::endl;
	}

	void printAction(){
	std::cout<<count<<"action="<<action<<std::endl;
	}

	void printLocNastere(){
	std::cout<<count<<"Loc nastere="<<locNastere<<std::endl;
	}
	
	~Rassa(){
	std::cout<<"Rassa sestructor!"<<std::endl;
	}
};

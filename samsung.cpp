#include <iostream>
#include "phone.cpp"
using namespace std;


class Samsung : private Phone{

    private:
		int price;

	public:
    	Samsung(int cust,std::string col,int p):Phone(cust, col){
        		price=p;   
	 	}	



    public: 
	int printPrice(){
        std::cout<<"price="<<price<<std::endl;
        return this->price;
	}


     std::string printColor(){
	    std::cout<<"color="<<color<<std::endl;
	    return this->color;
	}


    void setColor(std::string color){
	this->color=color;
	}


};

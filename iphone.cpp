#include <iostream>
#include "phone.cpp"
using namespace std;


class Iphone : private Phone{

    private:
		int price;


	public:
    	Iphone(int cust,std::string col,int p):Phone(cust, col){
        		price=p;   
	 	}	



    Iphone(const Iphone &ip):Phone(customers,color){
        std::cout<<"COPY CONSTRUCT!"<<std::endl;
        this->customers=ip.customers;
        this->color=ip.color;
        this->price=ip.price;
    }

     Iphone& operator=(const Iphone& ip){
        std::cout<<"COPY ASSIGNMENT OPERATOR!"<<std::endl;
        Phone::operator=(ip);
        price=ip.price;
        return *this;
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


    ~Iphone(){
        std::cout<<"DESTRUCT IPHONE!"<<std::endl;
    }

};
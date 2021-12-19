#include <iostream>

using namespace std;

class Phone{

	protected:
	int customers;
	std::string color;

   

    public:
	Phone (int cust, std::string col) 
    : customers(cust),
    color(col)
    {}
    
    Phone(const Phone &p){
        std::cout<<"COPY CONSTRUCT!"<<std::endl;
        this->customers=p.customers;
        this->color=p.color;
    }

    Phone& operator+=(const Phone& p){
        std::cout<<"OPERATOR +=!"<<std::endl;
        this->customers=p.customers;
        this->color=p.color;
        return *this;
    }

    
    Phone& operator=(const Phone &p){
        if(this == &p){
             std::cout<<"Identity test! Self assignment!"<<std::endl;
             return *this;
         }
    
        std::cout<<"SWAP!"<<std::endl;
        this->customers=p.customers;
        this->color=p.color;
        return *this;
    }

	public: 
    std::string printColor(){
	    std::cout<<"color="<<color<<std::endl;
	    return this->color;
	}



	void setColor(std::string color){
	    this->color=color;
	}



	int printCustomers(){
	    std::cout<<"customers="<<customers<<std::endl;
	    return this->customers;
    }


    ~Phone(){
        std::cout<<"DESTRUCT PHONE!"<<std::endl;
    }

};
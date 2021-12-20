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
    
    private: Phone(const Phone &p){
        std::cout<<"COPY CONSTRUCT!"<<std::endl;
        this->customers=p.customers;
        this->color=p.color;
    }

    private: Phone& operator=(const Phone& p){
        std::cout<<"Copy assignment operator!"<<std::endl;
        this->customers=p.customers;
        this->color=p.color;
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




class Iphone : private Phone{

    private:
		int price;


	public:
    	Iphone(int cust,std::string col,int p):Phone(cust, col){
        		price=p;   
	 	}	



    private: Iphone(const Iphone &ip):Phone(customers,color){
        std::cout<<"COPY CONSTRUCT!"<<std::endl;
        this->customers=ip.customers;
        this->color=ip.color;
        this->price=ip.price;
    }

     Iphone& operator=(const Iphone& ip){
        std::cout<<"COPY ASSIGNMENT OPERATOR!"<<std::endl;
        this->customers=ip.customers;
        this->color=ip.color;
        this->price=ip.price;
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



int main(){

	
    Iphone *iphone1=new Iphone(10,"verde",10000);

    iphone1->printPrice();

	std::cout<<"***********"<<std::endl;

	Iphone *iphone2=new Iphone(20,"rosu",1001);

	iphone2->printColor();

    std::cout<<"***********"<<std::endl;

	iphone2->setColor("verde");

	iphone2->printColor();
    

    /*Phone p1 (100,"rosu");
    Phone p2 (20,"alb");
    Phone p3 (10,"negru");
    p2.printColor();
    p2+=p1;
    p2.printColor(); //Item10
    std::cout<<"***********"<<std::endl;

    p3 = p1;
    p3=p3;//Item11
    std::cout<<"***********"<<std::endl;

    Iphone iphone1(10,"mov",100);
    Iphone iphone2(20,"roz",170);
    std::cout<<iphone1.printColor()<<std::endl;
    iphone1=iphone2;
    std::cout<<iphone1.printColor()<<std::endl;//Item12*/
}
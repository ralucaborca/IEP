#include <iostream>
#include <mutex>
#include <memory>
#include <thread>
using namespace std;

class Lock{
    std::mutex m;
    int ct=0;

    explicit Lock(){
        m.lock();
        std::cout<<"Constructor is called!"<<std::endl;
    }
    ~Lock(){
        m.unlock();
        std::cout<<"Destructor is called!"<<std::endl;
    }

    void takePictures(){
        Lock lock;
        ct++;
        std::cout<<"Customer number "<<ct<<" is taking pictures!"<<std::endl;

    }
    void finishing(){
        Lock lock;
        std::cout<<"Next customer is taking pictures!"<<std::endl;
    }
};

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
	    //std::cout<<"color="<<color<<std::endl;
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


    Phone* createPhone(int customers,std::string color){
        return (new Phone(customers,color));
    }

    std::mutex m;

    void takePictures(){
        m.lock();
        std::cout << "Phone bun!!" << "\n";
        m.unlock();
    }

int main(){

    //Item 13
    std::unique_ptr<Phone> pPhone(createPhone(100,"rosu"));
    std::cout<<pPhone->printColor()<<std::endl;
    //std::unique_ptr<Phone> pPhone1(pPhone); 
    std::unique_ptr<Phone> pPhone1 = move(pPhone);
    std::cout<<pPhone1->printColor()<<std::endl;
    
    std::shared_ptr<Phone> pPhone2(createPhone(10,"verde"));
    std::cout<<pPhone2->printColor()<<std::endl;
    std::shared_ptr<Phone> pPhone3(pPhone2);
    std::cout<<pPhone2->printColor()<<std::endl;
    std::cout<<pPhone3->printColor()<<std::endl;
    pPhone2=pPhone3;
    std::cout<<pPhone2->printColor()<<std::endl;
    std::cout<<pPhone3->printColor()<<std::endl;

    //Item 14
    std::thread picture1(takePictures);
    std::thread picture2(takePictures);
    picture1.join();
    picture2.join();
}
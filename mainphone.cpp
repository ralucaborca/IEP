#include <iostream>
#include "iphone.cpp"



using namespace std;

int main(){
	
	Phone p1 (100,"rosu");
    Phone p2 (20,"alb");
    Phone p3 (10,"negru");
    p2.printColor();
    p2+=p1;
    p2.printColor(); //Item10

    p3 = p1;
    p3=p3;//Item11

    Iphone iphone1(10,"mov",100);
    Iphone iphone2(20,"roz",170);
    std::cout<<iphone1.printColor()<<std::endl;
    iphone1=iphone2;
    std::cout<<iphone1.printColor()<<std::endl;//Item12
}

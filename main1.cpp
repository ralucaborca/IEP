#include <../inc/poriect.hpp>
#include <chrono>
#include <ctime>  
#include <iostream> 
#include <string>

int main()
{
    hello::Hello hello{};
    
    hello.start();
    
    hello.run();
    
    hello.stop();
    
    return 0;
}

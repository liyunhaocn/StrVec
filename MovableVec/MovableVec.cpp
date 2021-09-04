#include <iostream>
#include <vector>
#include "../util/Vector.h"
#include "../util/funGlobal.h"

#define debug(x) std::cout<<#x<<": "<<(x)<<std::endl;

using util::println;


int main()
{
    util::Vector v(10,7);
    std::vector<int> v1(10,7);
    
    int a = 10;
    println("a", a);

    return 0;
}

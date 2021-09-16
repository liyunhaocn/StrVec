#include <iostream>
#include <vector>
#include <algorithm>
#include "../util/Vector.h"
#include "../util/funGlobal.h"

#define debug(x) std::cout<<#x<<": "<<(x)<<std::endl;

using util::println;


int main()
{
    std::vector<int> v1(10, 7);
    std::vector<int> v2 = v1;

    util::Vector v3(10,7);
    util::Vector v4 = v3;
    
    v3[2] = 4;

    v3.show();
    v4.show();

    for (auto i : v3) {
        std::cout << i << std::endl;
    }

    std::swap(v3,v4);

    int a = 10;
    println("a", a);

    return 0;
}

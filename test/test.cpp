#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdarg>
#include "../tinystl/tiny_vector.h"
#include "../tinystl/util.h"
#include "../tinystl/allocator.h"

#define debug(x) std::cout<<#x<<": "<<(x)<<std::endl;
#pragma warning(disable:4996)

using util::println;
using std::cin;
using std::cout;
using std::endl;


bool test_max() {
    auto m = std::max({ 1,2,43,4,5,6,7,8,2,2, });
    debug(m)
        return true;
}

bool test_list() {

    std::list<int> li = { 1,2,4,5,6,7 };
    for (auto i : li) {
        debug(i)
    }
    // li = {1,32,4,5,5,6};
    li.sort([](int a, int b) {return true; });

    return true;
}

template<typename T>
using Vec = tstd::vector<T>;


template<typename T>
void showArr(T& arr) {
    for (auto& i : arr) {
        cout << i << ", ";
    }
    cout << endl;
}

bool test_vector() {

    tstd::vector<tstd::vector<int>> v2;
    v2.push_back({ 1,2 });
    v2.push_back({ 1,2 });
    return true;

}

void test_destory() {

    tstd::vector<int> v2 = { 1,2,3 };

    for (auto i : v2) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{

    // test_max();
    // test_list();
    // commit 1
    // commit 2
    
    //std::vector<int>v;
    //debug(util::getNameOfT(tstd::vector<int>::value_type{}));

    test_vector();
    //test_destory();

    return 0;
}
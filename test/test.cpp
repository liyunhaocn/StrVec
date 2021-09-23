#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdarg>
#include "../tinystl/tiny_vector.h"
#include "../tinystl/util.h"

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

    std::vector<int> v0(10, 7);

    struct pos {
        int x;
        int y;
    };
    //tstd::vector<tstd::vector<int>> v3;

    auto test_push_back = []() {

        tstd::vector<int> v = { 1,23,4,56,65 };
        v[3] = 10000;

        showArr(v);

        for (int i = 0; i < 100; ++i) {
            //showArr(v);
            debug(v.size())
                debug(v.capacity())
                v.push_back(i);
        }
    };

    auto test_sort = []() {
        tstd::vector<int> v = { 1,23,4,56,65 };
        std::sort(v.begin(), v.end());
        showArr(v);
    };

    test_sort();

    return true;

}

int main()
{

    // test_max();
    // test_list();

    test_vector();

    return 0;
}
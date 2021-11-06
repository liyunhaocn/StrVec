#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdarg>
#include <stack>
#include <string>

#include <tinystl/tiny_allocator.h>
#include <tinystl/tiny_vector.h>
#include <tinystl/tiny_loging.h>
#include <tinystl/tiny_util.h>
#include <tinystl/tiny_string.h>

#pragma warning(disable:4996)

#define SUFFIX(msg) std::string(msg).append("  <")\
                    .append(__FILENAME__).append("> <").append(__FUNCTION__)\
                    .append("> <").append(std::to_string(__LINE__))\
                    .append(">").c_str()


using util::println;
using std::cin;
using std::cout;
using std::endl;


bool test_max() {
    auto m = std::max({ 1,2,43,4,5,6,7,8,2,2, });
    spdlog::info("m: {}",m);
    return true;
}

bool test_list() {

    std::list<int> li = { 1,2,4,5,6,7 };
    for (auto i : li) {
        SPDLOG_DEBUG(i);
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

    std::stack<int, tstd::vector<int>>st;

    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty())
    {
        st.pop();
    }

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

    //test_vector();
    //test_destory();
    /*tstd::string s;
    tstd::string::value_type;*/

    std::string s = "fdsaf";

    spdlog::info("test for spd log {}", __FUNCTION__);


    return 0;
}
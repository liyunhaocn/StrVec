#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdarg>
#include <stack>

#include <xutility>

#include <assert.h>

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

using std::cin;
using std::cout;
using std::endl;


bool test_max() {
    auto m = std::max({ 1,2,43,4,5,6,7,8,2,2, });
    INFO("m: {}",m);
    return true;
}

bool test_list() {

    std::list<int> li = { 1,2,4,5,6,7 };
    for (auto i : li) {
        DEBUG(i);
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

    //std::string s = "fdsaf";

    std::cout << "[===============================================================]\n";
    std::cout << "[----------------- Run container test : vector -----------------]\n";
    std::cout << "[-------------------------- API test ---------------------------]\n";
    int a[] = { 1,2,3,4,5 };
    tstd::vector<int> v1;
    tstd::vector<int> v2(10);
    tstd::vector<int> v3(10, 1);
    tstd::vector<int> v4(a, a + 5);
    tstd::vector<int> v5(v2);
    tstd::vector<int> v6(std::move(v2));
    tstd::vector<int> v7{ 1,2,3,4,5,6,7,8,9 };
    tstd::vector<int> v8, v9, v10;
    v8 = v3;
    v9 = std::move(v3);
    v10 = { 1,2,3,4,5,6,7,8,9 };

    FUN_AFTER(v1, v1.assign(8, 8));
    FUN_AFTER(v1, v1.assign(a, a + 5));
    FUN_AFTER(v1, v1.emplace(v1.begin(), 0));
    FUN_AFTER(v1, v1.emplace_back(6));
    FUN_AFTER(v1, v1.push_back(6));
    //FUN_AFTER(v1, v1.insert(v1.end(), 7));
    //FUN_AFTER(v1, v1.insert(v1.begin() + 3, 2, 3));
    //FUN_AFTER(v1, v1.insert(v1.begin(), a, a + 5));
    FUN_AFTER(v1, v1.pop_back());
    FUN_AFTER(v1, v1.erase(v1.begin()));
    FUN_AFTER(v1, v1.erase(v1.begin(), v1.begin() + 2));
    FUN_AFTER(v1, v1.erase(v1.begin(), v1.begin() + 2));
    
    //using it = std::vector<int>::iterator;
    
    //cout << (std::_Is_input_iter_v<it> == true) << endl;

    //INFO("_Is_input_iter_v:{}", std::_Is_input_iter_v<it> );

    return 0;
}
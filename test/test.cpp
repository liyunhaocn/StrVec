#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdio>
#include <cstdarg>
#include <stack>
#include <string>

#include <xutility>

#include <assert.h>

#include <tinystl/tiny_allocator.h>
#include <tinystl/tiny_vector.h>
#include <tinystl/tiny_loging.h>
#include <tinystl/tiny_util.h>
#include <tinystl/tiny_string.h>


#pragma warning(disable:4996)

/*
* ²âÊÔÑùÀýÀ´×Ô https://github.com/Alinshans/MyTinySTL
* 
* 
* 
*/
using std::cin;
using std::cout;
using std::endl;


template<typename T>
void showArr(T& arr) {
    for (auto& i : arr) {
        cout << i << ", ";
    }
    cout << endl;
}

void test_string() {

    std::cout << "[===============================================================]" << std::endl;
    std::cout << "[----------------- Run container test : string -----------------]" << std::endl;
    std::cout << "[-------------------------- API test ---------------------------]" << std::endl;
    

    const char* s = "abcdefg";
    tstd::string str;
    tstd::string str1(5, 'a');

    std::string a = "fdsafsdfsad";
    std::string b(a,4);
    tstd::string str2(str1, 3);

    tstd::string str3(str1, 0, 3);
    tstd::string str4("abc");
    tstd::string str5("abcde", 3);
    tstd::string str6(s, s + 5);
    tstd::string str7(str1);
    tstd::string str8(std::move(str1));
    tstd::string str9;
    str9 = str2;
    tstd::string str10;
    str10 = std::move(str2);
    tstd::string str11;
    str11 = "123";
    tstd::string str12;
    str12 = 'A';

    STR_FUN_AFTER(str, str = "string");
    FUN_VALUE(*str.rbegin());
    FUN_VALUE(*(str.end() - 1));
    FUN_VALUE(*(str.rend() - 1));
    FUN_VALUE(str.front());
    FUN_VALUE(str.back());
    FUN_VALUE(str[1]);
    STR_COUT(str.c_str());
    std::cout << std::boolalpha;
    FUN_VALUE(str.empty());
    std::cout << std::noboolalpha;
    FUN_VALUE(str.size());
    FUN_VALUE(str.length());
    FUN_VALUE(str.capacity());
    FUN_VALUE(str.max_size());
    FUN_VALUE(str.capacity());

    //STR_FUN_AFTER(str, str.insert(str.begin(), 'a'));
    //STR_FUN_AFTER(str, str.insert(str.end(), 3, 'x'));
    //STR_FUN_AFTER(str, str.insert(str.end(), s, s + 3));
    //STR_FUN_AFTER(str, str.erase(str.begin()));
    //STR_FUN_AFTER(str, str.erase(str.begin(), str.begin() + 3));
    //STR_FUN_AFTER(str, str.clear());
    //STR_FUN_AFTER(str, str.push_back('s'));
    //STR_FUN_AFTER(str, str.push_back('t'));
    //STR_FUN_AFTER(str, str.pop_back());
    //STR_FUN_AFTER(str, str.append(1, 't'));
    //STR_FUN_AFTER(str, str.append(str4));
    //STR_FUN_AFTER(str, str.append(str4, 1));
    //STR_FUN_AFTER(str, str.append(str4, 2, 1));
    //STR_FUN_AFTER(str, str.append("str"));
    //STR_FUN_AFTER(str, str.append("inging", 3));
    //STR_FUN_AFTER(str, str.append(s, s + 3));
    //STR_FUN_AFTER(str, str.resize(10));
    //FUN_VALUE(str.size());
    //STR_FUN_AFTER(str, str.resize(20, 'x'));
    //FUN_VALUE(str.size());
    //STR_FUN_AFTER(str, str.clear());

    //STR_FUN_AFTER(str, str = "string");
    //STR_FUN_AFTER(str3, str3 = "astrings");

    //FUN_VALUE(str.substr(0));
    //FUN_VALUE(str.substr(3));
    //FUN_VALUE(str.substr(0, 3));
    //FUN_VALUE(str.substr(0, 10));
    //STR_FUN_AFTER(str, str.replace(0, 6, str3));
    //STR_FUN_AFTER(str, str.replace(str.end() - 1, str.end(), str3));
    //STR_FUN_AFTER(str, str.replace(0, 1, "my "));
    //STR_FUN_AFTER(str, str.replace(str.end() - 8, str.end(), " test"));
    //STR_FUN_AFTER(str, str.replace(10, 4, "replace"));
    //STR_FUN_AFTER(str, str.replace(str.end(), str.end(), " test"));
    //STR_FUN_AFTER(str, str.replace(0, 2, 3, '6'));
    //STR_FUN_AFTER(str, str.replace(str.begin(), str.begin() + 3, 6, '6'));
    //STR_FUN_AFTER(str, str.replace(0, 3, str3, 1, 3));
    //STR_FUN_AFTER(str, str.replace(str.begin(), str.begin() + 6, s, s + 3));
    //STR_FUN_AFTER(str, str.reverse());
    //STR_FUN_AFTER(str, str.reverse());

    //STR_FUN_AFTER(str, str = "abcabc stringgg");
    //STR_FUN_AFTER(str3, str3 = "abc");
    //FUN_VALUE(str.find('a'));
    //FUN_VALUE(str.find('a', 3));
    //FUN_VALUE(str.find('a', 4));
    //FUN_VALUE(str.find("abc"));
    //FUN_VALUE(str.find("abc", 1));
    //FUN_VALUE(str.find("abc", 1, 1));
    //FUN_VALUE(str.find(str3));
    //FUN_VALUE(str.find(str3, 1));

    //FUN_VALUE(str.count('a'));
    //FUN_VALUE(str.count('a', 2));
    //FUN_VALUE(str.count('d', 10));

    //STR_FUN_AFTER(str, str.swap(str3));
    //FUN_VALUE(str.size());
    //FUN_VALUE(str.length());
    //FUN_VsALUE(str.capacity());
    //STR_FUN_AFTER(str, str += str);
    //STR_FUN_AFTER(str, str += 'a');
    //STR_FUN_AFTER(str, str += "bc");
    //FUN_VALUE(str.size());
    //FUN_VALUE(str.length());
    //FUN_VALUE(str.capacity());
    //STR_FUN_AFTER(str, str.shrink_to_fit());
    //FUN_VALUE(str.capacity());
    //STR_FUN_AFTER(str, str.reserve(50));
    //FUN_VALUE(str.capacity());
    //STR_FUN_AFTER(str3, str3 = "test");
    //STR_FUN_AFTER(str4, str4 = " ok!");
    //std::cout << " str3 + '!' : " << str3 + '!' << std::endl;
    //std::cout << " '#' + str3 : " << '#' + str3 << std::endl;
    //std::cout << " str3 + \" success\" : " << str3 + " success" << std::endl;
    //std::cout << " \"My \" + str3 : " << "My " + str3 << std::endl;
    //std::cout << " str3 + str4 : " << str3 + str4 << std::endl;
}

void test_vec() {
    
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
    FUN_AFTER(v1, v1.insert(v1.end(), 7));
    FUN_AFTER(v1, v1.pop_back());
    FUN_AFTER(v1, v1.erase(v1.begin()));
    FUN_AFTER(v1, v1.erase(v1.begin(), v1.begin() + 2));
    FUN_AFTER(v1, v1.erase(v1.begin(), v1.begin() + 2));
    
}

int main()
{

    //test_vec();

    tstd::string s1 = "fdasfsada";
    tstd::string s2 = s1;

    INFO("s1:{}",s1);
    INFO("s2:{}",s2);
    s1[0] = '5';

    INFO("s1:{}", s1);
    INFO("s2:{}", s2);

    tstd::vector< tstd::string > v;

    v.push_back("a");
    v.push_back("bb");
    v.push_back("ccc");
    v.push_back("dddd");

    for (auto i : v) {
        INFO("ele: {}",i);
    }

    auto v2 = v;

    for (auto i : v2) {
        INFO("ele: {}", i);
    }
    //test_string();

    return 0;
}
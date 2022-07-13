#ifndef CN_HUST_LYH_LOGING_H
#define CN_HUST_LYH_LOGING_H


#include <chrono>

#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"
#include "spdlog/fmt/ostr.h"

#define GET_FILE_INFO(x) {              \
    std::cerr                           \
    << "[" << __DATE__<<":"             \
    << __TIME__ << "]"                  \
    << "[" << __FILE__                  \
    << " line:" << __LINE__ << "]: ";   \
}

#define SUFFIX(msg) std::string(msg).append("  <")\
                    .append(__FILENAME__).append("> <").append(__FUNCTION__)\
                    .append("> <").append(std::to_string(__LINE__))\
                    .append(">").c_str()

//#define INFO(...) 

#define INFO(...)   spdlog::info(## __VA_ARGS__)

#define DEBUG(...) spdlog::debug(## __VA_ARGS__)
#define WARN(...) spdlog::warn(## __VA_ARGS__)
#define ERR(...) spdlog::error(## __VA_ARGS__)

#define LOG_ERR(x) do{GET_FILE_INFO();std::cerr<<(x)<<std::endl;}while(0);

// 遍历输出容器
#define COUT(container) do {                             \
  std::string con_name = #container;                     \
  std::cout << " " << con_name << " :";                  \
  for (auto it : container)                              \
    std::cout << " " << it;                              \
  std::cout << "\n";                                     \
} while(0)

// 输出容器调用函数后的结果
#define FUN_AFTER(con, fun) do {                         \
  std::string fun_name = #fun;                           \
  std::cout << " After " << fun_name << " :\n";          \
  fun;                                                   \
  COUT(con);                                             \
} while(0)

// 输出容器调用函数的值
#define FUN_VALUE(fun) do {                              \
  std::string fun_name = #fun;                           \
  std::cout << " " << fun_name << " : " << fun << "\n";  \
} while(0)

#define STR_FUN_AFTER(str, fun) do {                     \
  std::string fun_name = #fun;                           \
  std::cout << " After " << fun_name << " :\n";          \
  fun;                                                   \
  STR_COUT(str);                                         \
} while(0)

#define STR_COUT(str) do {                               \
  std::string str_name = #str;                           \
  std::cout << " " << str_name << " : " << str << "\n";  \
} while(0)

//#define debug(x) std::cout<<#x<<": "<<(x)<<std::endl;

#endif // !CN_HUST_LYH_LOGING_H
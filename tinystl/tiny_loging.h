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


#define INFO(...) spdlog::info(## __VA_ARGS__)
#define DEBUG(...) spdlog::debug(## __VA_ARGS__)
#define WARN(...) spdlog::warn(## __VA_ARGS__)
#define ERR(...) spdlog::error(## __VA_ARGS__)

#define LOG_ERR(x) do{GET_FILE_INFO();std::cerr<<(x)<<std::endl;}while(0);

// �����������
#define COUT(container) do {                             \
  std::string con_name = #container;                     \
  std::cout << " " << con_name << " :";                  \
  for (auto it : container)                              \
    std::cout << " " << it;                              \
  std::cout << "\n";                                     \
} while(0)

// ����������ú�����Ľ��
#define FUN_AFTER(con, fun) do {                         \
  std::string fun_name = #fun;                           \
  std::cout << " After " << fun_name << " :\n";          \
  fun;                                                   \
  COUT(con);                                             \
} while(0)


//#define debug(x) std::cout<<#x<<": "<<(x)<<std::endl;

#endif // !CN_HUST_LYH_LOGING_H
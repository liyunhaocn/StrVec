#ifndef CN_HUST_LYH_LOGING_H
#define CN_HUST_LYH_LOGING_H


#define GET_FILE_INFO(x) {              \
    std::cerr                           \
    << "[" << __DATE__<<":"             \
    << __TIME__ << "]"                  \
    << "[" << __FILE__                  \
    << " line:" << __LINE__ << "]: ";   \
}

#define LOG_ERR(x) do{GET_FILE_INFO();std::cerr<<(x)<<std::endl;}while(0);

#define debug(x) std::cout<<#x<<": "<<(x)<<std::endl;

#endif // !CN_HUST_LYH_LOGING_H
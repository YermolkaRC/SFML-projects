#include "logger.hpp"

std::ofstream Logger::m_Out;

void Logger::Init(std::string file_to_log){
    if (file_to_log.empty()) {
        file_to_log = "output.log";
    }
    m_Out.open(file_to_log); 
}

void Logger::Debug_log(std::string text){
#ifdef __DEBUG__
    m_Out << "DEBUG: " << text << "\n";
#endif

#ifdef __DEBUG_COUT__
    std::cout << "DEBUG: " << text << "\n";
#endif
}

void Logger::Log(std::string text){
    m_Out << text << "\n";
#ifdef __DEBUG_COUT__
    std::cout << "LOG: " << text << "\n";
#endif
}


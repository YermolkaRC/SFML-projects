#ifndef SFML_PROJECT_LOGGER_HPP
#define SFML_PROJECT_LOGGER_HPP

#include <iostream>
#include <fstream>

#define __DEBUG__
#define __DEBUG_COUT__

class Logger {
    protected:
    static std::ofstream m_Out;
    Logger() {}

    public:
    static void Init(std::string file_to_log = "output.log");
    static void Debug_log(std::string text);
    static void Log(std::string text);
};

#endif
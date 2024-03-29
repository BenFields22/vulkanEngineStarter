#include "tools/Utils.hpp"

#ifdef _WIN32
Logger::Logger(std::string id, int logFlag, int color) {
  loggerId = id;
  loggerFlag = logFlag;
  loggerColor = color;
}

void Logger::print(std::string text) {
  if (loggerFlag == 1) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), loggerColor);
    std::cout << "[" << loggerId << "]";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    std::cout << ":" << text << std::endl;
  }
}
#else
Logger::Logger(std::string id, int logFlag, int color) {
  loggerId = id;
  loggerFlag = logFlag;
  loggerColor = "\033[0;" + std::to_string(color) + "m";
}

void Logger::print(std::string text) {
  if (loggerFlag == 1) {
    std::cout << loggerColor << loggerId << "\033[0;37m"
              << ":" << text << std::endl;
  }
}

std::string Logger::getID() { return this->loggerId; }
#endif

Logger::~Logger() { print("Shutting Down Logger"); }
CheckPoint *appLog = new CheckPoint();

void log(int debuging, CheckPoint *myAppLog, Logger *logger, std::string s) {
  if (debuging) {
    std::string noteString = "[";
    noteString += logger->getID();
    noteString += "]";
    noteString += s;
    myAppLog->note(noteString);
    logger->print(s);
  }
}

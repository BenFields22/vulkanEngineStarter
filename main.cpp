
#include "first_app.hpp"
#include "tools/Utils.hpp"
// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>
int DEBUG_ACTIVE = 1;
int main() {

  Logger *mainLogger = new Logger("MAIN", 1, MAGENTA);
  log(DEBUG_ACTIVE, appLog, mainLogger, "Main Entry Point into Application");
  lve::FirstApp app{};

  try {
    app.run();
  } catch (const std::exception &e) {
    Logger *errorLogger = new Logger("ERROR", 1, RED);
    log(DEBUG_ACTIVE, appLog, errorLogger, "PROGRAM CRASHED");
    std::string errorMessage = e.what();
    errorMessage = "Error message \"" + errorMessage + "\"";
    log(DEBUG_ACTIVE, appLog, errorLogger, errorMessage);
    appLog->dumpLog(DEBUG_ACTIVE);
    return EXIT_FAILURE;
  }
  if (DEBUG_ACTIVE) {
    log(DEBUG_ACTIVE, appLog, mainLogger, "Safely Shut Down");
    appLog->dumpLog(DEBUG_ACTIVE);
  }

  return EXIT_SUCCESS;
}

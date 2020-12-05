#include <iostream>
#include <iomanip>
#include "DatabaseHandler.h"
#include "TerminalQuestionnaire.h"

int main() {
    Logger* l = Logger::getLogger("log.txt");
    TerminalQuestionnaire test(3, 50);
    test.Start();
    /*Logger logger;
    logger.LOG_WARN("Test warning");
    logger.LOG_ERROR("Test error");
    logger.LOG_INFO("Test info");*/
}

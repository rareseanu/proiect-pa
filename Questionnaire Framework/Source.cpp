#include <iostream>
#include <iomanip>
#include "DatabaseHandler.h"
#include "QuestionnaireFramework.h"
#include "Logger.h"

int main() {
    Logger* l = Logger::getLogger("log.txt");
    QuestionnaireFramework questionnaire(2,20);
   try {
        questionnaire.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    }
    catch (std::string error){
        LOG_ERROR(error);
    }
    questionnaire.LoadQuestions("question","answer");
    questionnaire.SelectQuestions(std::vector<std::string> {"Mate", "SA"});
    questionnaire.Start();
    /*Logger logger;
    logger.LOG_WARN("Test warning");
    logger.LOG_ERROR("Test error");
    logger.LOG_INFO("Test info");*/
}

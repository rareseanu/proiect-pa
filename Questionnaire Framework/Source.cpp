#include <iostream>
#include <iomanip>
#include "DatabaseHandler.h"
#include "QuestionnaireFramework.h"
#include "Logger.h"

int main() {
    Logger* l = Logger::getLogger("log.txt");
    QuestionnaireFramework questionnaire(2);
   try {
        questionnaire.openDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    }
    catch (std::string error){
        LOG_ERROR(error);
    }
    questionnaire.loadQuestions("question","answer");
    questionnaire.selectQuestions(std::vector<std::string> {"Mate", "SA"});
    questionnaire.printQuestions(questionnaire.getSelectedQuestions());
    std::cout << "\n\n" << questionnaire.getMaximumMark();
    questionnaire.start();
}

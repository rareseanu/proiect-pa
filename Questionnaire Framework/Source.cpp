#include <iostream>
#include <iomanip>
#include "DatabaseHandler.h"
#include "QuestionnaireFramework.h"

int main() {
    QuestionnaireFramework questionnaire(2);
   try {
        questionnaire.openDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    }
    catch (std::string error){
        std::cout << error;
    }
    questionnaire.loadQuestions("question","answer");
    questionnaire.selectQuestions(std::vector<std::string> {"Mate", "SA"});
    questionnaire.printQuestions(questionnaire.getSelectedQuestions());
    std::cout << "\n\n" << questionnaire.getMaximumMark();
    questionnaire.start();
}

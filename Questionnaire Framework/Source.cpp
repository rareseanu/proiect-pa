#include <iostream>
#include <iomanip>
#include "DatabaseHandler.h"
#include "QuestionnaireFramework.h"


int main() {
    QuestionnaireFramework questionnaire;
    try {
        questionnaire.openDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
    }
    catch (std::string error){
        std::cout << error;
    }
    questionnaire.loadQuestions();
    questionnaire.printQuestions();
}

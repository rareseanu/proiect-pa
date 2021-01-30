#include "pch.h"
#include "CppUnitTest.h"
#include "QuestionnaireFramework.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuestionnaireFrameworkTests
{
	TEST_CLASS(QuestionnaireTests)
	{
	public:

		TEST_METHOD(CheckQuestionSelection)
		{
			QuestionnaireFramework quiz(10, true, true, true);
			quiz.SetNumberOfQuestions(2);
			quiz.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
			quiz.SetQuestionsTable("testquestion", "q_id", "text", "points", "category", "type");
			quiz.SetAnswersTable("testanswer", "a_id", "text", "percentage", "q_id");
			quiz.LoadQuestions();
			quiz.SelectQuestions(std::vector<std::string> { "test" });
			Assert::AreEqual(quiz.GetSelectedQuestions()->at(0).GetText() , std::string("Test question"));
		}

		TEST_METHOD(CheckFinalGrade)
		{
			QuestionnaireFramework quiz(10, true, true, true);
			quiz.SetNumberOfQuestions(2);
			quiz.SetMaximumGrade(50);
			quiz.OpenDatabase("yufioaba", "ruby.db.elephantsql.com", "5432", "yufioaba", "ZGnmR5rJdvvkXXove7sqUQGNB5-lHNoO");
			quiz.SetQuestionsTable("testquestion", "q_id", "text", "points", "category", "type");
			quiz.SetAnswersTable("testanswer", "a_id", "text", "percentage", "q_id");
			quiz.LoadQuestions();
			quiz.SelectQuestions(std::vector<std::string> { "test" });
			quiz.GetSelectedQuestions()->at(0).GiveAnswer("abc");
			quiz.CalculateFinalGrade();
			Assert::AreEqual((int)quiz.GetFinalGrade(), quiz.GetMaximumGrade());
		}
	};
}

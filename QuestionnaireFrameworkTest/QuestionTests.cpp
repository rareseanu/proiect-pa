#include "pch.h"
#include "CppUnitTest.h"
#include "QuestionnaireFramework.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuestionnaireFrameworkTests
{
	TEST_CLASS(QuestionsTests)
	{
	public:

		TEST_METHOD(TypeToString)
		{
			Question question;
			std::string questionType = "Singlechoice";
			question.SetQuestionType(Question::QuestionType::Singlechoice);
			Assert::AreEqual(Question::ConvertQuestionTypeToString(question.GetQuestionType()), questionType);
		}

		TEST_METHOD(StringToType)
		{
			Question question;
			std::string questionType = "Singlechoice";
			question.SetQuestionType(Question::ConvertStringToQuestionType(questionType));
			Assert::IsTrue(question.GetQuestionType() == Question::QuestionType::Singlechoice);
		}

		TEST_METHOD(QuestionText)
		{
			Question question;
			question.SetText("Test question?");
			Assert::AreEqual(question.GetText(), std::string("Test question?"));
		}

		TEST_METHOD(CheckAcquiredMark)
		{
			Answer answer1(0, "Answer1", 33.3, false);
			Answer answer2(1, "Answer2", 33.3, false);
			Answer answer3(2, "Answer3", 33.3, false);
			Answer answer4(3, "Answer4", -100, false);
			std::vector<Answer> answers{ answer1, answer2, answer3, answer4};
			Question question(0, "Question", 100, "Category", answers, false, Question::QuestionType::Multichoice);
		
			question.SetAnswers(answers);
			question.GiveAnswer("abc");
			Assert::AreEqual(question.GetAquiredMark(), 100.0f);
		}

	};
}

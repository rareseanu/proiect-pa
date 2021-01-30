#include "pch.h"
#include "CppUnitTest.h"
#include "QuestionnaireFramework.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuestionnaireFrameworkTests
{
	TEST_CLASS(AnswerTests)
	{
	public:

		TEST_METHOD(CheckConstructor)
		{
			Answer answer(0, "Answer1", 50, false);
			Assert::AreEqual(answer.GetId(), 0);
			Assert::AreEqual(answer.GetAnswer(), std::string("Answer1"));
			Assert::AreEqual((int) answer.GetPercent(), 50);
			Assert::AreEqual(answer.GetSelected(), false);
		}

		TEST_METHOD(CheckSelected)
		{
			Answer answer(0, "Answer1", 50, false);
			answer.SetSelected(true);
			Assert::AreNotEqual(answer.GetSelected(), false);
		}
	};
}

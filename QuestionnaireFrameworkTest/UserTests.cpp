#include "pch.h"
#include "CppUnitTest.h"
#include "QuestionnaireFramework.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuestionnaireFrameworkTests
{
	TEST_CLASS(UserTests)
	{
	public:
		
		TEST_METHOD(CheckName)
		{
			User user;
			user.SetFirstName("Lungu");
			user.SetLastName("Dragos");
			Assert::AreEqual(user.GetFirstName() + " " + user.GetLastName(), user.GetName());
		}

		TEST_METHOD(CheckGrade)
		{
			User user;
			user.SetGrade(10);
			Assert::AreEqual(user.GetGrade(), (float) 10);
		}

	};
}

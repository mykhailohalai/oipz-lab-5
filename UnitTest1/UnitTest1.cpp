#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\1\Desktop\Завдання унік\ОІПЗ\ЛАБИ\lab_5\lab_5\lab_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(testY)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = -1;
			double n = 4;
			double expected = 1;
			double actual = y(x, n);

			Assert::AreEqual(expected, actual);
		}

	public:


		TEST_METHOD(TestMethod2)
		{
			double x = 1;
			double n = 4;
			double expected = 3584;
			double actual = y(x, n);

			Assert::AreEqual(expected, actual);
		}

	public:

		TEST_METHOD(TestMethod3)
		{
			double x = 0;
			double n = 4;
			double expected = 1504;
			double actual = y(x, n);

			Assert::AreEqual(expected, actual);
		}

	public:

		TEST_METHOD(TestMethod4)
		{
			double x = 0;
			double n = 4;
			double expected = 100000000000000;
			double actual = y(x, n);

			Assert::AreEqual(expected, actual);
		}
	};
}

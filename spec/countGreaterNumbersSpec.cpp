#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/countGreaterNumbers.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(countGreaterNumbersSpec)
	{
	public:

		TEST_METHOD(dateNotPresent)
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "11-11-2015");
			Assert::AreEqual(0, count, L"count should be 0", LINE_INFO());
		}

		TEST_METHOD(lastDate)
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "29-11-2007");
			Assert::AreEqual(0, count, L"count should be 0", LINE_INFO());
		}

		TEST_METHOD(sameDatesArray)
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "09-10-2003", "Second" }, { 30, "09-10-2003", "Third" }, { 90, "09-10-2003", "Fourth" }, { 10, "09-10-2003", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "09-10-2003");
			Assert::AreEqual(0, count, L"count should be 0", LINE_INFO());
		}

		TEST_METHOD(firstDate)
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "09-10-2003");
			Assert::AreEqual(4, count, L"count should be 4", LINE_INFO());
		}

		TEST_METHOD(middleDate)
		{
			struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
			int count = countGreaterNumbers(Arr, 5, "03-03-2005");
			Assert::AreEqual(2, count, L"count should be 2", LINE_INFO());
		}

	};
}
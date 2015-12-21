#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/findSingleOccurenceNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(findSingleOccurenceNumberSpec)
	{
	public:

		TEST_METHOD(nullCheck)
		{
			Assert::AreEqual(findSingleOccurenceNumber(NULL, 2), -1, L"Null check failed.", LINE_INFO());
		}

		TEST_METHOD(sortedArray)
		{
			int A[7] = { 2, 2, 2, 3, 6, 6, 6 };
			Assert::AreEqual(findSingleOccurenceNumber(A, 7), 3, L"sorted Array case failed.", LINE_INFO());

			int A1[7] = { 2, 2, 2, 3, 3, 3, 6 };
			Assert::AreEqual(findSingleOccurenceNumber(A1, 7), 6, L"sorted Array case failed.", LINE_INFO());

			int A2[7] = { 2, 3, 3, 3, 6, 6, 6 };
			Assert::AreEqual(findSingleOccurenceNumber(A2, 7), 2, L"sorted Array case failed.", LINE_INFO());
		}

		TEST_METHOD(unSortedArray)
		{
			int A[10] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 3 };
			Assert::AreEqual(findSingleOccurenceNumber(A, 10), 2, L"un sorted Array case failed.", LINE_INFO());

			int A1[10] = { 12, 1, 2, 3, 2, 1, 1, 2, 3, 3 };
			Assert::AreEqual(findSingleOccurenceNumber(A1, 10), 12, L"un sorted Array case failed.", LINE_INFO());

			int A2[10] = { 12, 1, 12, 3, 12, 2, 2, 2, 3, 3 };
			Assert::AreEqual(findSingleOccurenceNumber(A2, 10), 1, L"un sorted Array case failed.", LINE_INFO());
		}

	};
}
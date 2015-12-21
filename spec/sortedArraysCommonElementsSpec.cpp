#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/sortedArraysCommonElements.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(sortedArraysCommonElementsSpec)
	{
	public:

		bool compare(struct transaction *actual, struct transaction *expected, int length) {
			for (int i = 0; i < length; ++i) {
				if (actual[i].amount != expected[i].amount) {
					return false;
				}
			}
			return true;
		}

		TEST_METHOD(NullCheck)
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			Assert::IsNull(sortedArraysCommonElements(NULL, 3, NULL, 3), L"Null Check failed.", LINE_INFO());
			Assert::IsNull(sortedArraysCommonElements(A, 3, NULL, 3), L"Null Check failed.", LINE_INFO());
			Assert::IsNull(sortedArraysCommonElements(NULL, 3, A, 3), L"Null Check failed.", LINE_INFO());
		}

		TEST_METHOD(noCommonElements)
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
			//int A[3] = { 1, 2, 3 }, B[3] = { 4, 5, 6 };
			Assert::IsNull(sortedArraysCommonElements(A, 3, B, 3), L"No common elements Check failed.", LINE_INFO());
		}

		TEST_METHOD(sameArray)
		{
			struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			//int A[3] = { 1, 2, 3 }, expected[3] = { 1, 2, 3 };
			struct transaction expected[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
			struct transaction *result = sortedArraysCommonElements(A, 3, A, 3);
			Assert::IsTrue(compare(result, expected, 3), L"All common elements Check failed.", LINE_INFO());
		}

		TEST_METHOD(radomCommonElements)
		{
			struct transaction A[5] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" } };
			struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "22nd" }, { 320, "27-08-2015", "32nd" } };
			//int A[5] = { 1, 2, 3, 4, 5 }, B[3] = { 1, 22, 32 }, expected[1] = { 1 };
			struct transaction expected[3] = { { 10, "09-10-2003", "First" } };
			struct transaction *result = sortedArraysCommonElements(A, 5, B, 3);
			Assert::IsTrue(compare(result, expected, 1), L"One common element Check failed.", LINE_INFO());
		}
	};
}
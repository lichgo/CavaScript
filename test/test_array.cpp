#include "stdafx.h"
#include "CppUnitTest.h"

#include "Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace cavascript;

namespace UnitTest
{
	TEST_CLASS(UnitTestArray)
	{
	public:
		Array<int> arr;

		TEST_METHOD(length)
		{
			Assert::AreEqual(arr.length, 0);
		}

		TEST_METHOD(indexOf)
		{
			arr.push(1);
			arr.push(2);
			arr.push(3);

			Assert::AreEqual(arr.indexOf(2), 1);
		}

	};
}
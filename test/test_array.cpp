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

		TEST_METHOD(Array)
		{
			Assert::AreEqual(arr.length, 0);

			arr.push(1);
			arr.push(2);
			arr.push(3);
			arr.push(1);

			Assert::AreEqual(arr.indexOf(2), 1);

			Assert::AreEqual(arr.lastIndexOf(1), 3);

			arr.unshift(0);

			Assert::AreEqual(arr[0], 0);

			Assert::AreEqual(arr.length, 5);
		}

	};
}
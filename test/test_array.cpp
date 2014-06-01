#include "stdafx.h"
#include "CppUnitTest.h"

#include "CavaArray.h"
#include "CavaString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace cavascript;

namespace UnitTest
{
	TEST_CLASS(UnitTestArray)
	{
	public:
		Array<int> arr;
		Array<int> arr2;

		TEST_METHOD(Array)
		{
			Assert::AreEqual(arr.length, 0);

			arr.push(1);
			arr.push(2);
			arr.push(3);
			arr.push(1);

			Assert::AreEqual( (arr.join() == String("1,2,3,1") ), true);

			Assert::AreEqual(arr.length, 4);

			Assert::AreEqual(arr.indexOf(2), 1);

			Assert::AreEqual(arr.lastIndexOf(1), 3);

			Assert::AreEqual((arr.join() == String("1,2,3,1")), true);

			arr.unshift(0);

			Assert::AreEqual((arr.join() == String("0,1,2,3,1")), true);

			Assert::AreEqual(arr[0], 0);

			Assert::AreEqual(arr.length, 5);

			Assert::AreEqual((arr.splice(2, 2).join('\0') == String("23")), true);
			Assert::AreEqual((arr.join('|') == String("0|1|1")), true);

		}

	};
}
#include "stdafx.h"
#include "CppUnitTest.h"

#include "CavaString.h"
#include "CavaArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace cavascript;

namespace UnitTest
{
	TEST_CLASS(UnitTestArray)
	{
	public:
		Array<int> arr;
		Array<int> arr2;

		TEST_METHOD(ArrayGenreral)
		{
			Assert::AreEqual((int)arr.length, 0);

			arr.push(1);
			arr.push(2);
			arr.push(3);
			arr.push(1);

			Assert::AreEqual( (arr.join() == String("1,2,3,1") ), true);

			Assert::AreEqual((int)arr.length, 4);

			Assert::AreEqual(arr.indexOf(2), 1);

			Assert::AreEqual(arr.lastIndexOf(1), 3);

			Assert::AreEqual((arr.join() == String("1,2,3,1")), true);

			arr.unshift(0);

			Assert::AreEqual((arr.join() == String("0,1,2,3,1")), true);

			Assert::AreEqual(arr[0], 0);

			Assert::AreEqual((int)arr.length, 5);

			Assert::AreEqual((arr.splice(2, 2).join('\0') == String("23")), true);
			Assert::AreEqual((arr.join('|') == String("0|1|1")), true);

		}

		TEST_METHOD(StringGeneral)
		{
			String str1("abc123ABC");

			Assert::AreEqual((int)str1.length, 9);
			Assert::AreEqual(str1.charAt(3), '1');
			Assert::AreEqual((int)str1.charCodeAt(3), 49);
			Assert::AreEqual((str1.toLowerCase() == String("abc123abc")), true);
			Assert::AreEqual((str1.substr(2, 4) == String("c123")), true);
			Assert::AreEqual((str1.toLowerCase() == String("abc123abc")), true);
			Assert::AreEqual((str1.slice(2, 4) == str1.substring(2, 4)), true);
			Assert::AreEqual((str1.slice(1, 5) == String("bc12")), true);
			Assert::AreEqual((str1.slice(1, 5).toUpperCase() == String("BC12")), true);
			Assert::AreEqual((str1.slice(-6, -1) == String("123AB")), true);
		}

	};
}
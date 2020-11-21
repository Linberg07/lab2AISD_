#include "pch.h"
#include "CppUnitTest.h"
#include "../2laba/algorithm.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2labatest
{
	TEST_CLASS(My2labatest)
	{
	public:
		
		TEST_METHOD(isCorrectSortTest) {
			int a[] = { 1,2,3,4,5 };
			Assert::IsTrue(isSorted(a, 5) == 1);
		}
		TEST_METHOD(isCorrectnoSortTest) {
			int a[] = { 1,7,2,1,7 };
			Assert::IsTrue(isSorted(a, 5) == 0);
		}
		TEST_METHOD(BinarySearchTest)
		{
			int a[] = { 1,2,3,4,5,6 };
			int index;
			index = Binary_Search(a, 6, 4);
			Assert::IsTrue(index == 3);
		}
		TEST_METHOD(BinarySearchunCorrectTest) {
			int a[] = { 1,2,3,4,5,6 };
			int index;
			try {
				index = Binary_Search(a, -1, 5);
			}
			catch(const char* warning){
				Assert::AreEqual(warning, "Uncorrect size");
			}
		}
		TEST_METHOD(BinarySearchnoSortTest) {
			int a[] = { 1,6,2,7,2 };
			int index;
			try {
				index = Binary_Search(a, 5, 6);
			}
			catch(const char* warning){
				Assert::AreEqual(warning, "Array is not Sorted!");
			}
		}
		TEST_METHOD(QuickSortTest) {
			int a[] = { 1,6,2,7,8,1 };
			QuickSort(a, 6);
			Assert::IsTrue(isSorted(a, 6) == 1);
		}
		TEST_METHOD(QuickSortunCorrectTest) {
			int a[] = { 1,2,5,4,7,2 };
			try {
				QuickSort(a, -1);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Uncorrect Size!");
			}
		}
		TEST_METHOD(QuicknoSortTest) {
			int a[] = { 1,2,3,4,5 };
			QuickSort(a, 5);
			Assert::IsTrue(isSorted(a, 5) == 1);
		}
		TEST_METHOD(InsertionSortTest) {
			int a[] = { 1,6,7,5,4 };
			InsertionSort(a, 5);
			Assert::IsTrue(isSorted(a, 5) == 1);
		}
		TEST_METHOD(InsertionSortunCorrectTest) {
			int a[] = { 1,5,2,6,2 };
			try {
				InsertionSort(a, -1);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Uncorrect Size!");
			}
		}
		TEST_METHOD(InsertionSortnoSort) {
			int a[] = { 1,2,3,4,5 };
			InsertionSort(a, 5);
			Assert::IsTrue(isSorted(a, 5) == 1);
		}
		TEST_METHOD(BogoSortTest) {
			int a[] = { 1,5,2,6,7 };
			BogoSort(a, 5);
			Assert::IsTrue(isSorted(a, 5) == 1);
		}
		TEST_METHOD(BogoSortunCorrectTest) {
			int a[] = { 1,6,2,4,6 };
			try {
				BogoSort(a, -1);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Uncorrect Size!");
			}
		}
		TEST_METHOD(BogoSortnoSortTest) {
			int a[] = { 1,2,3,4,5 };
			BogoSort(a, 5);
			Assert::IsTrue(isSorted(a,5) == 1);
		}
		TEST_METHOD(CountingSortTest) {
			char a[] = { 'b','c','d','a' };
			char b[4];
			CountingSort(a, b, 4);
			Assert::IsTrue((b[0] == 'a') && (b[3] == 'd'));
		}
		TEST_METHOD(CountingSortunCorrectTest) {
			char a[] = { 'b','c','d','a' };
			char b[4];
			try {
				CountingSort(a, b, -1);
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "Uncorrect Size!");
			}
		}
		TEST_METHOD(CountingSortnoSort) {
			char a[] = { 'a','b','c','d' };
			char b[4];
			CountingSort(a, b, 4);
			Assert::IsTrue((b[0] == 'a') && (b[1] == 'b') && (b[2] == 'c') && (b[3] == 'd'));
		}
	};
}

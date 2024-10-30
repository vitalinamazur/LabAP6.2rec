#include "pch.h"
#include "CppUnitTest.h"
#include "../LabAP6.2rec/LabAP6.2rec.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForArrayProcessing
{
    TEST_CLASS(UnitTestForArrayProcessing)
    {
    public:

        TEST_METHOD(TestCreateArray)
        {
            const int n = 10;
            int arr[n];
            int Low = 1, High = 50;

            CreateArray(arr, n, Low, High);

            for (int i = 0; i < n; i++) {
                Assert::IsTrue(arr[i] >= Low && arr[i] <= High);
            }
        }

        TEST_METHOD(TestFindMaxOddElement)
        {
            const int n = 5;

            int arr1[n] = { 3, 7, 15, 2, 9 };
            int maxOdd1 = FindMaxOddElement(arr1, n);
            Assert::AreEqual(15, maxOdd1); 

            int arr2[n] = { 2, 4, 6, 8, 10 };
            int maxOdd2 = FindMaxOddElement(arr2, n);
            Assert::AreEqual(-1, maxOdd2); 

            int arr3[n] = { 2, 4, 6, 8, 11 };
            int maxOdd3 = FindMaxOddElement(arr3, n);
            Assert::AreEqual(11, maxOdd3); 

            int arr4[n] = { 7, 7, 7, 7, 7 };
            int maxOdd4 = FindMaxOddElement(arr4, n);
            Assert::AreEqual(7, maxOdd4); 
        }
    };
}

#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_2_rek/lab_7_2_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMinRow)
        {
            const int cols = 5;
            int** a = new int* [1];
            a[0] = new int[cols] { 5, 3, 8, 1, 4 };
            int min = a[0][0];

            MinRow(a, 0, cols, 0, min);
            Assert::AreEqual(min, 1);

            delete[] a[0];
            delete[] a;
        }

        TEST_METHOD(TestMaxMinRows)
        {
            const int rows = 3;
            const int cols = 4;
            int** a = new int* [rows];


            a[0] = new int[cols] { 1, 2, 3, 4 };
            a[1] = new int[cols] { 9, 8, 7, 5 };
            a[2] = new int[cols] { 5, 4, 6, 8 };

            int max;

            MaxMinRows(a, rows, cols, 0, max);
            Assert::AreEqual(max, 5);

            // Звільнення пам'яті
            for (int i = 0; i < rows; i++)
                delete[] a[i];
            delete[] a;
        }

	};
}

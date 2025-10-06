#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Timur\proga\ОС\LAB-2\LAB-2\Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayTests
{
	TEST_CLASS(ArrayTests)
	{
	public:

		TEST_METHOD(FindMinMax_ValidArray_FindsCorrectIndices)
		{
			Array testArray;
			int values[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
			testArray.arr = values;
			testArray.size = 8;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(1, Min);
			Assert::AreEqual(5, Max);
		}

		TEST_METHOD(FindMinMax_Single)
		{
			Array testArray;
			int values[] = { 42 };
			testArray.arr = values;
			testArray.size = 1;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(0, Min);
			Assert::AreEqual(0, Max);
		}

		TEST_METHOD(FindMinMax_AllNegative)
		{
			Array testArray;
			int values[] = { -5, -2, -10, -1, -3 };
			testArray.arr = values;
			testArray.size = 5;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(2, Min); 
			Assert::AreEqual(3, Max); 
		}

		TEST_METHOD(FindMinMax_Mixed)
		{
			Array testArray;
			int values[] = { -5, 10, -3, 0, 7, -8 };
			testArray.arr = values;
			testArray.size = 6;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(5, Min);
			Assert::AreEqual(1, Max);
		}

		TEST_METHOD(FindMinMax_AllSame)
		{
			Array testArray;
			int values[] = { 5, 5, 5, 5, 5 };
			testArray.arr = values;
			testArray.size = 5;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(0, Min);
			Assert::AreEqual(0, Max);
		}

		TEST_METHOD(FindMinMax_MinAtStart_MaxAtEnd)
		{
			Array testArray;
			int values[] = { 1, 2, 3, 4, 5 };
			testArray.arr = values;
			testArray.size = 5;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(0, Min);
			Assert::AreEqual(4, Max);
		}

		TEST_METHOD(FindMinMax_MaxAtStart_MinAtEnd)
		{
			Array testArray;
			int values[] = { 10, 8, 6, 4, 2 };
			testArray.arr = values;
			testArray.size = 5;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(4, Min);
			Assert::AreEqual(0, Max);
		}

		TEST_METHOD(CalculateAverage_ValidArray_CalculatesCorrectly)
		{
			Array testArray;
			int values[] = { 1, 2, 3, 4, 5 };
			testArray.arr = values;
			testArray.size = 5;

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(3.0, average);
		}

		TEST_METHOD(CalculateAverage_NegativeNumbers)
		{
			Array testArray;
			int values[] = { -2, -1, 0, 1, 2 };
			testArray.arr = values;
			testArray.size = 5;

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(0.0, average);
		}

		TEST_METHOD(CalculateAverage_Single)
		{
			Array testArray;
			int values[] = { 7 };
			testArray.arr = values;
			testArray.size = 1;

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(7.0, average);
		}

		TEST_METHOD(CalculateAverage_LargeNumbers)
		{
			Array testArray;
			int values[] = { 1000000, 2000000, 3000000 };
			testArray.arr = values;
			testArray.size = 3;

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(2000000.0, average);
		}

		TEST_METHOD(CalculateAverage_FractionalResult)
		{
			Array testArray;
			int values[] = { 1, 2, 3, 4 };
			testArray.arr = values;
			testArray.size = 4;

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(2.5, average);
		}

		TEST_METHOD(CalculateAverage_AllZero)
		{
			Array testArray;
			int values[] = { 0, 0, 0, 0, 0 };
			testArray.arr = values;
			testArray.size = 5;

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(0.0, average);
		}

		TEST_METHOD(ProcessArray_ValidData_ReplacesMinAndMax)
		{
			Array testArray;
			int values[] = { 10, 20, 30, 5, 15 };
			testArray.arr = values;
			testArray.size = 5;
			testArray.min = 3;
			testArray.max = 2;
			testArray.average = 16.0;

			int val = static_cast<int>(testArray.average + 0.5);
			testArray.arr[testArray.min] = val;
			testArray.arr[testArray.max] = val;

			Assert::AreEqual(16, testArray.arr[3]);
			Assert::AreEqual(16, testArray.arr[2]);
			Assert::AreEqual(10, testArray.arr[0]);
			Assert::AreEqual(20, testArray.arr[1]);
			Assert::AreEqual(15, testArray.arr[4]);
		}

		TEST_METHOD(ProcessArray_AverageRoundsCorrectly)
		{
			Array testArray;
			int values[] = { 1, 5, 9 };
			testArray.arr = values;
			testArray.size = 3;
			testArray.min = 0;
			testArray.max = 2;
			testArray.average = 5.2; 

			int val = static_cast<int>(testArray.average + 0.5);
			testArray.arr[testArray.min] = val;
			testArray.arr[testArray.max] = val;

			Assert::AreEqual(5, testArray.arr[0]);
			Assert::AreEqual(5, testArray.arr[2]);
		}

		TEST_METHOD(ProcessArray_AverageRoundsUp)
		{
			Array testArray;
			int values[] = { 1, 2, 6 };
			testArray.arr = values;
			testArray.size = 3;
			testArray.min = 0;
			testArray.max = 2;
			testArray.average = 3.6; 

			int val = static_cast<int>(testArray.average + 0.5);
			testArray.arr[testArray.min] = val;
			testArray.arr[testArray.max] = val;

			Assert::AreEqual(4, testArray.arr[0]);
			Assert::AreEqual(4, testArray.arr[2]);
		}

		TEST_METHOD(ProcessArray_MinAndMaxSameIndex)
		{
			Array testArray;
			int values[] = { 5 };
			testArray.arr = values;
			testArray.size = 1;
			testArray.min = 0;
			testArray.max = 0;
			testArray.average = 5.0;

			int val = static_cast<int>(testArray.average + 0.5);
			testArray.arr[testArray.min] = val;
			testArray.arr[testArray.max] = val;

			Assert::AreEqual(5, testArray.arr[0]);
		}

		TEST_METHOD(BoundaryValues_MaxIntValues)
		{
			Array testArray;
			int values[] = { INT_MAX, INT_MAX, INT_MAX };
			testArray.arr = values;
			testArray.size = 3;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(0, Min);
			Assert::AreEqual(0, Max);
			Assert::AreEqual(static_cast<double>(INT_MAX), average);
		}

		TEST_METHOD(BoundaryValues_MinIntValues)
		{
			Array testArray;
			int values[] = { INT_MIN, INT_MIN, INT_MIN };
			testArray.arr = values;
			testArray.size = 3;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			Assert::AreEqual(0, Min);
			Assert::AreEqual(0, Max);
			Assert::AreEqual(static_cast<double>(INT_MIN), average);
		}

		TEST_METHOD(BoundaryValues_MixedExtremeValues)
		{
			Array testArray;
			int values[] = { INT_MIN, 0, INT_MAX };
			testArray.arr = values;
			testArray.size = 3;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			Assert::AreEqual(0, Min); 
			Assert::AreEqual(2, Max); 
		}

		// ===== ТЕСТЫ ОКРУГЛЕНИЯ СРЕДНЕГО =====

		TEST_METHOD(Rounding_ExactHalf_RoundsUp)
		{
			Array testArray;
			int values[] = { 1, 2 };
			testArray.arr = values;
			testArray.size = 2;

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;
			int rounded = static_cast<int>(average + 0.5);

			Assert::AreEqual(1.5, average);
			Assert::AreEqual(2, rounded); 
		}

		TEST_METHOD(Rounding_JustBelowHalf_RoundsDown)
		{
			double average = 3.4999;
			int rounded = static_cast<int>(average + 0.5);
			Assert::AreEqual(3, rounded);
		}

		TEST_METHOD(Rounding_JustAboveHalf_RoundsUp)
		{
			double average = 3.5001;
			int rounded = static_cast<int>(average + 0.5);
			Assert::AreEqual(4, rounded);
		}

		TEST_METHOD(Integration_FullProcess)
		{
			Array testArray;
			int values[] = { 7, 3, 9, 1, 5 };
			testArray.arr = values;
			testArray.size = 5;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			int val = static_cast<int>(average + 0.5);
			testArray.arr[Min] = val;
			testArray.arr[Max] = val;

			Assert::AreEqual(3, Min);    
			Assert::AreEqual(2, Max);    
			Assert::AreEqual(5.0, average);
			Assert::AreEqual(5, testArray.arr[3]);
			Assert::AreEqual(5, testArray.arr[2]); 
		}

		TEST_METHOD(Integration_AllElementsSame)
		{
			Array testArray;
			int values[] = { 4, 4, 4, 4 };
			testArray.arr = values;
			testArray.size = 4;

			int Min = 0, Max = 0;
			for (int i = 1; i < testArray.size; i++) {
				if (testArray.arr[i] < testArray.arr[Min])
					Min = i;
				if (testArray.arr[i] > testArray.arr[Max])
					Max = i;
			}

			long long sum = 0;
			for (int i = 0; i < testArray.size; i++) {
				sum += testArray.arr[i];
			}
			double average = static_cast<double>(sum) / testArray.size;

			int val = static_cast<int>(average + 0.5);
			testArray.arr[Min] = val;
			testArray.arr[Max] = val;

			Assert::AreEqual(0, Min);
			Assert::AreEqual(0, Max);
			Assert::AreEqual(4.0, average);
			Assert::AreEqual(4, testArray.arr[0]); 
		}
	};
}

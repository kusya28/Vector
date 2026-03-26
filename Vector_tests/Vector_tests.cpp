#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\NewRepo\Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vectortests
{
	TEST_CLASS(Vectortests)
	{
	public:
		
		// Тест генерації вектора
        TEST_METHOD(TestGenerateVectorSize) {
            int size = 10;
            auto v = generateVector(size);
            Assert::AreEqual(size, (int)v.size()); // Перевіряємо чи розмір вірний
        }

        // Тест суми вектора
        TEST_METHOD(TestSumVector) {
            std::vector<double> v = { 1.0, 2.0, 3.5 };
            double expected = 6.5;
            Assert::AreEqual(expected, sumVector(v), 0.001); // 0.001 - похибка для double
        }

        // Тест сортування (ASC)
        TEST_METHOD(TestSortASC) {
            std::vector<double> v = { 3.0, 1.0, 2.0 };
            sortASC(v);
            Assert::IsTrue(v[0] == 1.0 && v[2] == 3.0);
        }

        // Тест видалення дублікатів
        TEST_METHOD(TestRemoveDuplicates) {
            std::vector<double> v = { 1.0, 1.0, 2.0 };
            int repeats = 0;
            auto unique = removeDuplicates(v, repeats);
            Assert::AreEqual(1, repeats); // Має бути 1 повтор
            Assert::AreEqual(2, (int)unique.size()); // Має залишитись 2 числа
        }

        // Тест групування
        TEST_METHOD(TestGroupSums) {
            std::vector<double> v = { 1.0, 2.0, 3.0, 4.0 };
            int groupSize = 2; // групи {1,2} та {3,4}
            auto sums = groupSums(v, groupSize);
            Assert::AreEqual(2, (int)sums.size());
            Assert::AreEqual(3.0, sums[0], 0.001); // 1+2
            Assert::AreEqual(7.0, sums[1], 0.001); // 3+4
        }

        // Тест сортування DESC
        TEST_METHOD(TestSortDESC) {
            std::vector<double> v = { 1.0, 5.0, 2.0 };
            sortDESC(v);
            Assert::IsTrue(v[0] == 5.0 && v[2] == 1.0);
        }

        // Тест пошуку максимальної групи
        TEST_METHOD(TestMaxGroup) {
            std::vector<double> v = { 1.0, 2.0, 10.0, 20.0, 1.0, 1.0 };
            int n = 2; // групи: {1,2}=3, {10,20}=30, {1,1}=2
            auto best = maxGroup(v, n);
            Assert::AreEqual(10.0, best[0]);
            Assert::AreEqual(20.0, best[1]);
        }
	};
}

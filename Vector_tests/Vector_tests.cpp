#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\NewRepo\Vector.h"
#include "C:\Users\User\source\repos\NewRepo\json.hpp" 
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using json = nlohmann::json;

json allTestResults = json::array();

namespace Vectortests
{
    TEST_CLASS(Vectortests)
    {
    public:

        TEST_CLASS_CLEANUP(WriteJsonReport)
        {
            std::ofstream file("test_report.json");
            if (file.is_open()) {
                file << std::setw(4) << allTestResults << std::endl;
                file.close();
            }
        }

        void LogResult(std::string name, bool passed, double expected = 0, double actual = 0) {
            allTestResults.push_back({
                {"test_name", name},
                {"status", passed ? "PASSED" : "FAILED"},
                {"expected", expected},
                {"actual", actual},
                {"timestamp", __TIME__}
                });
        }

        TEST_METHOD(TestGenerateVectorSize) {
            int size = 10;
            auto v = generateVector(size);
            bool passed = ((int)v.size() == size);
            LogResult("TestGenerateVectorSize", passed, size, (double)v.size());
            Assert::AreEqual(size, (int)v.size());
        }

        TEST_METHOD(TestSumVector) {
            std::vector<double> v = { 1.0, 2.0, 3.5 };
            double expected = 6.5;
            double actual = sumVector(v);
            bool passed = (std::abs(expected - actual) < 0.001);
            LogResult("TestSumVector", passed, expected, actual);
            Assert::AreEqual(expected, actual, 0.001);
        }

        TEST_METHOD(TestSortASC) {
            std::vector<double> v = { 3.0, 1.0, 2.0 };
            sortASC(v);
            bool passed = (v[0] == 1.0 && v[2] == 3.0);
            LogResult("TestSortASC", passed);
            Assert::IsTrue(passed);
        }

        TEST_METHOD(TestSortDESC) {
            std::vector<double> v = { 1.0, 5.0, 2.0 };
            sortDESC(v);
            bool passed = (v[0] == 5.0 && v[2] == 1.0);
            LogResult("TestSortDESC", passed);
            Assert::IsTrue(passed);
        }

        TEST_METHOD(TestRemoveDuplicates) {
            std::vector<double> v = { 1.0, 1.0, 2.0 };
            int repeats = 0;
            auto unique = removeDuplicates(v, repeats);
            bool passed = (repeats == 1 && unique.size() == 2);
            LogResult("TestRemoveDuplicates", passed, 1, (double)repeats);
            Assert::AreEqual(1, repeats);
            Assert::AreEqual(2, (int)unique.size());
        }

        TEST_METHOD(TestGroupSums) {
            std::vector<double> v = { 1.0, 2.0, 3.0, 4.0 };
            auto sums = groupSums(v, 2);
            bool passed = (sums.size() == 2 && sums[0] == 3.0 && sums[1] == 7.0);
            LogResult("TestGroupSums", passed, 7.0, sums.size() > 1 ? sums[1] : 0);
            Assert::AreEqual(3.0, sums[0], 0.001);
            Assert::AreEqual(7.0, sums[1], 0.001);
        }

        TEST_METHOD(TestMaxGroup) {
            std::vector<double> v = { 1.0, 1.0, 10.0, 10.0, 2.0, 2.0 };
            auto best = maxGroup(v, 2);
            double sum = best[0] + best[1];
            bool passed = (sum == 20.0);
            LogResult("TestMaxGroup", passed, 20.0, sum);
            Assert::AreEqual(20.0, sum, 0.001);
        }
    };
}
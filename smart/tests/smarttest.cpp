#include <smart.h>
#include "smarttest.h"
#include <numeric>
#include <iostream>

void SmartTest::tableTest_data()
{
    QTest::addColumn<bool>("result");
    QTest::addColumn<std::vector<int>>("array");

    QTest::newRow("All odds array") << true << (std::vector<int>) {3, 3, 3};
    QTest::newRow("1 out of 3 is even array") << false << (std::vector<int>) {3, 2, 3};
    QTest::newRow("All odds with negatives array") << true << (std::vector<int>) {-3, 1, -3};
    QTest::newRow("Empty array") << false << (std::vector<int>) {};
}

void SmartTest::tableTest()
{
    QFETCH(bool, result);
    QFETCH(std::vector<int>, array);

    QCOMPARE(Smart::threeConsecutiveOdds(array), result);
}

void SmartTest::test1()
{
    std::vector<int> arr {3, 3, 3};
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}

void SmartTest::pushBackTest()
{
    std::vector<int> arr {3, 3};
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
    arr.push_back(5);
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}

void SmartTest::highIntTest()
{
    int int_MAX = std::numeric_limits<int>::max();
    std::vector<int> arr1 {int_MAX, int_MAX, int_MAX};
    QVERIFY(Smart::threeConsecutiveOdds(arr1));
}

void SmartTest::negativeIntTest()
{
    std::vector<int> arr {1, 4, 5, -3, 7, 8};
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}

void SmartTest::bigArrayTest()
{
    std::vector<int> arr(100000000);
    std::iota(arr.begin(), arr.end(), 0);

    arr.push_back(3);
    arr.push_back(551);
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}

QTEST_APPLESS_MAIN(SmartTest)

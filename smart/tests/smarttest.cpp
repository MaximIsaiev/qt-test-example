#include <smart.h>
#include "smarttest.h"

void SmartTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void SmartTest::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}

void SmartTest::exampleTest()
{
    std::vector<int> arr {2,6,4,1};
    std::vector<int> arr1 {1,2,34,3,4,5,7,23,12};
    Smart smart;
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
    QVERIFY(Smart::threeConsecutiveOdds(arr1));
}

void SmartTest::test1()
{
    std::vector<int> arr{};
    std::vector<int> arr1 {(3+2),1,1,1,1,0,0,0,0,0,0};
    std::vector<int> arr2 {(76-187),35,81,54,920,6538};
    Smart smart;
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
    QVERIFY(Smart::threeConsecutiveOdds(arr1));
    QVERIFY(Smart::threeConsecutiveOdds(arr2));
}

void SmartTest::threeConsecutiveOdds_data()
{
    QTest::addColumn<std::vector<int>>("array");
    QTest::addColumn<bool>("result");

    QTest::newRow("array") << (std::vector<int>) {} << false;
    QTest::newRow("array1") << (std::vector<int>) {(3+2),1,1,1,1,0,0,0,0,0,0} << true;
    QTest::newRow("array2") << (std::vector<int>) {(76-187),35,81,54,920,6538} << true;
}

void SmartTest::threeConsecutiveOdds()
{
    QFETCH(std::vector<int>, array);
    QFETCH(bool, result);

    QCOMPARE(Smart::threeConsecutiveOdds(array), result);
}

QTEST_APPLESS_MAIN(SmartTest)

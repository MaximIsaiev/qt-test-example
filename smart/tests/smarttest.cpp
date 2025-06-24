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
    std::vector<int> arr { };
    std::vector<int> arr1 {(3+2), 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    std::vector<int> arr2 {(76-187), 35, 81, 54, 920, 6538};
    Smart smart;
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
    QVERIFY(Smart::threeConsecutiveOdds(arr1));
    QVERIFY(Smart::threeConsecutiveOdds(arr2));
}

void SmartTest::threeConsecutiveOdds_data()
{
    QTest::addColumn<std::vector<int>>("array");
    QTest::addColumn<bool>("result");

    QTest::newRow("array") << (std::vector<int>) { } << false;
    QTest::newRow("array1") << (std::vector<int>) {(3 + 2), (3 * 3), (25-18), (27 / 9)} << true;
    QTest::newRow("array2") << (std::vector<int>) {(76-187), 35, -81, 42, 920, 6538} << true;
    QTest::newRow("array3") << (std::vector<int>) {3, 3, 3, 3, 3, 3, 3} << true;
    QTest::newRow("array4") << (std::vector<int>) {1, 2, 3} << false;
    QTest::newRow("array5") << (std::vector<int>) {7, 9} << false;
    QTest::newRow("array6") << (std::vector<int>) {15} << false;
    QTest::newRow("array7") << (std::vector<int>) {94747291, 9439204, 273746, 174583, 2637845} << false;
    QTest::newRow("array8") << (std::vector<int>) {(13 / 5), 3, 9} << false;
}

void SmartTest::threeConsecutiveOdds()
{
    QFETCH(std::vector<int>, array);
    QFETCH(bool, result);

    QCOMPARE(Smart::threeConsecutiveOdds(array), result);
}

QTEST_APPLESS_MAIN(SmartTest)

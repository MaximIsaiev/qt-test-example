#include <smart.h>
#include "smarttest.h"

void SmartTest::initTestCase() {
    qDebug("Called before everything else.");
}

void SmartTest::cleanupTestCase() {
    qDebug("Called after myFirstTest and mySecondTest.");
}

void SmartTest::exampleTest() {
    Smart smart;
    QVERIFY(!smart.threeConsecutiveOdds(std::vector<int>{1, 3}));
    QVERIFY(!smart.threeConsecutiveOdds(std::vector<int>{1, 2, 3}));
    QVERIFY(smart.threeConsecutiveOdds(std::vector<int>{1, 5, 3}));
    QVERIFY(!smart.threeConsecutiveOdds(std::vector<int>{1, 2, 4, 6, 8, 10, 11, 13, 8, -1}));
    QVERIFY(smart.threeConsecutiveOdds(std::vector<int>{0, 1, 3, 5, 6}));
}

//void SmartTest::testData()
//{
//    QTest::addColumn<std::vector<int>>("array");
//    QTest::addColumn<bool>("result");
//
//    QTest::newRow("test_data_1") << std::vector<int> {2,6,4,1} << false;
//    QTest::newRow("test_data_2") << std::vector<int> {1,2,34,3,4,5,7,23,12} << true;
//    QTest::newRow("test_data_3") << std::vector<int> {1, 3} << false;
//    QTest::newRow("test_data_4") << std::vector<int> {1, 2, 3} << false;
//    QTest::newRow("test_data_5") << std::vector<int> {1, 3, 5} << true;
//}
//
//void SmartTest::exampleTest()
//{
//    Smart smart;
//    QFETCH(std::vector<int>, array);
//    QFETCH(bool, result);
//    QCOMPARE(smart.threeConsecutiveOdds(array), result);
//}

QTEST_APPLESS_MAIN(SmartTest)

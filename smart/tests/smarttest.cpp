#include <smart.h>
#include "smarttest.h"

void SmartTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void SmartTest::cleanupTestCase()
{
    qDebug("Called after last test func was executed.");
}


void SmartTest::threeConsecutiveOddsWithOnlyEven()
{
    std::vector<int> arr {2,6,4,1};
    Smart smart;
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
}
void SmartTest::threeConsecutiveOddsWithThreeOdds(){
    std::vector<int> arr {1,2,34,3,4,5,7,23,12};
    Smart smart;
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}
void SmartTest::threeConsecutiveOddsWithOnlyZeros(){
    std::vector<int> arr {0,0,0,0,0,0,0,0,0};
    Smart smart;
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
}
void SmartTest::threeConsecutiveOddsWithThreeNegativeOdds(){
    std::vector<int> arr {-9, -7, -5};
    std::vector<int> arr2 {-9, -7, -3};
    Smart smart;
    QEXPECT_FAIL("", "Vector1 isn't equal to vector2", Continue);
    QCOMPARE(arr, arr2);
    QVERIFY(Smart::threeConsecutiveOdds(arr2));
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}
void SmartTest::threeConsecutiveOddsWithNan(){
    std::vector<double> arr {1, 3, std::nan(""), 5, 7, std::nan("")};
    Smart smart;
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
}
void SmartTest::threeConsecutiveOdds_data(){
    QTest::addColumn<std::vector<int>>("vector");
    QTest::addColumn<bool>("result");

    QTest::newRow("data_1") << std::vector<int> {1,3,5,7,9,10,12,123,4,5,1} << true; 
    QTest::newRow("data_2") << std::vector<int> {2,4,6,8,1,2,6,2} << false;
    QTest::newRow("data_3") << std::vector<int> {-9,-7,-3} << true;
}
void SmartTest::threeConsecutiveOdds(){
    QFETCH(std::vector<int>, vector);
    QFETCH(bool, result);
    Smart smart;
    QCOMPARE(Smart::threeConsecutiveOdds(vector), result);
}
QTEST_APPLESS_MAIN(SmartTest)

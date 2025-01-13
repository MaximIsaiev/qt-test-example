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

void SmartTest::cleanup()
{
    qDebug("Called after every test func"); 
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
QTEST_APPLESS_MAIN(SmartTest)

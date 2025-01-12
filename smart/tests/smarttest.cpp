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

QTEST_APPLESS_MAIN(SmartTest)

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

void SmartTest::test1() {
    std::vector<int> arr{3, 3, 3};
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}


void SmartTest::pushBackTest() {
    std::vector<int> arr{3, 3};
    QVERIFY(!Smart::threeConsecutiveOdds(arr));
    arr.push_back(5);
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}

void SmartTest::highIntTest() {
    std::vector<int> arr1{2147483647, 2147483647, 2147483647};
    QVERIFY(Smart::threeConsecutiveOdds(arr1));
}

void SmartTest::negativeIntTest() {
    std::vector<int> arr{1, 4, 5, -3, 7, 8};
    qDebug("It should be true, right?");
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}

void SmartTest::bigArrayTest() {
    std::vector<int> arr;
    for(int i = 0; i < 100000000; i++) {
        arr.push_back(i);
        if(i == 9999999) {
            arr.push_back(3);
            arr.push_back(551);
        }
    }
    QVERIFY(Smart::threeConsecutiveOdds(arr));
}

QTEST_APPLESS_MAIN(SmartTest)

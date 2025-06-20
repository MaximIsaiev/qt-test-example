#include <smart.h>
#include "smarttest.h"

void SmartTest::tableTest_data() {
    QTest::addColumn<bool>("result");
    QTest::addColumn<std::vector<int>>("array");

    QTest::newRow("che-to tam 1") <<  true   << (std::vector<int>) {3, 3, 3};
    QTest::newRow("che-to tam 2") <<  false  << (std::vector<int>) {3, 2, 3};
    QTest::newRow("che-to tam 3") <<  true   << (std::vector<int>) {-3, 1, -3};
}

void SmartTest::tableTest()
{
    QFETCH(bool, result);
    QFETCH(std::vector<int>, array);

    QCOMPARE(Smart::threeConsecutiveOdds(array), result);
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

#include <smart.h>
#include "smarttest.h"

void SmartTest::tableTest_data() {
    QTest::addColumn<QString>("array");
    QTest::addColumn<bool>("result");

    std::vector<int> arr1{3, 3, 3};
    std::vector<int> arr2{3, 2, 3};
    std::vector<int> arr3{-3, 1, -3};

    QTest::newRow("che-to tam 1") << "true"  << Smart::threeConsecutiveOdds(arr1);
    QTest::newRow("che-to tam 2") << "false"  << Smart::threeConsecutiveOdds(arr2);
    QTest::newRow("che-to tam 3") << "true"  << Smart::threeConsecutiveOdds(arr3);
}

void SmartTest::tableTest()
{
    QFETCH(QString, array);
    QFETCH(bool, result);
    bool expected = static_cast<QVariant>(array).toBool();

    QCOMPARE(result, expected);
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

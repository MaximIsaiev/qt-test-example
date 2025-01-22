#include <thread>
#include <iostream>
#include "concurrentTest.h"

int result = 0;
using threadArgs = std::pair <void (Concurrent::*)(std::function<void()>), std::function<void()>>;

void concurrentTest::initTestCase() {
    qDebug("Called before everything else.");
}

int concurrentTest::startThreads(const std::vector<int> &order) {
    Concurrent concurrent;
    result = 0;

    std::function<void()> printFirst = []() {
        result *= 10;
        result += 1;
    };
    std::function<void()> printSecond = []() {
        result *= 10;
        result += 2;
    };
    std::function<void()> printThird = []() {
        result *= 10;
        result += 3;
    };

    std::vector<std::thread> threads;

    if (order.size() != 3) {
        return -1;
    } else {
        for (int i = 0; i < order.size(); i++){
            if (order.at(i) == 1) {
                threads.emplace_back(std::thread (&Concurrent::first, &concurrent, printFirst));
            } else if (order.at(i) == 2){
                threads.emplace_back(std::thread (&Concurrent::second, &concurrent, printSecond));
            } else {
                threads.emplace_back(std::thread (&Concurrent::third, &concurrent, printThird));
            }
        }

        for (int i = 0; i < order.size(); i++){
            threads.at(i).join();
        }

        return result;
    }


}

void concurrentTest::tableTest_data() {
    QTest::addColumn<std::vector<int>>("order");
    QTest::addColumn<int>("testResult");

    QTest::newRow("test_data_1") << std::vector<int>{1, 2, 3} << 123;
    QTest::newRow("test_data_2") << std::vector<int>{1, 3, 2} << 123;
    QTest::newRow("test_data_3") << std::vector<int>{2, 1, 3} << 123;
    QTest::newRow("test_data_4") << std::vector<int>{2, 3, 1} << 123;
    QTest::newRow("test_data_5") << std::vector<int>{3, 1, 2} << 123;
    QTest::newRow("test_data_6") << std::vector<int>{3, 2, 1} << 123;
};

void concurrentTest::tableTest() {
    QFETCH(std::vector<int>, order);
    QFETCH(int, testResult);

    QCOMPARE(startThreads(order), testResult);
};


void concurrentTest::cleanupTestCase() {
    qDebug("Called after myFirstTest and mySecondTest.");
}

QTEST_APPLESS_MAIN(concurrentTest)
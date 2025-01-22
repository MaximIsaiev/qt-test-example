#include <thread>
#include <iostream>
#include "concurrentTest.h"

int result = 0;

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

    if (order.size() != 3) {
        return -1;
    } else {
        if (order.at(0) == 1) {
            if (order.at(1) == 2) {
                std::thread thread1(&Concurrent::first, &concurrent, printFirst);
                std::thread thread2(&Concurrent::second, &concurrent, printSecond);
                std::thread thread3(&Concurrent::third, &concurrent, printThird);
                thread1.join();
                thread2.join();
                thread3.join();
            } else {
                std::thread thread1(&Concurrent::first, &concurrent, printFirst);
                std::thread thread3(&Concurrent::third, &concurrent, printThird);
                std::thread thread2(&Concurrent::second, &concurrent, printSecond);
                thread1.join();
                thread2.join();
                thread3.join();
            }
        } else if (order.at(0) == 2) {
            if (order.at(1) == 1) {
                std::thread thread2(&Concurrent::second, &concurrent, printSecond);
                std::thread thread1(&Concurrent::first, &concurrent, printFirst);
                std::thread thread3(&Concurrent::third, &concurrent, printThird);
                thread1.join();
                thread2.join();
                thread3.join();
            } else {
                std::thread thread2(&Concurrent::second, &concurrent, printSecond);
                std::thread thread3(&Concurrent::third, &concurrent, printThird);
                std::thread thread1(&Concurrent::first, &concurrent, printFirst);
                thread1.join();
                thread2.join();
                thread3.join();
            }
        } else {
            if (order.at(1) == 1) {
                std::thread thread3(&Concurrent::third, &concurrent, printThird);
                std::thread thread1(&Concurrent::first, &concurrent, printFirst);
                std::thread thread2(&Concurrent::second, &concurrent, printSecond);
                thread1.join();
                thread2.join();
                thread3.join();
            } else {
                std::thread thread3(&Concurrent::third, &concurrent, printThird);
                std::thread thread2(&Concurrent::second, &concurrent, printSecond);
                std::thread thread1(&Concurrent::first, &concurrent, printFirst);
                thread1.join();
                thread2.join();
                thread3.join();
            }
        }
    }

    return result;
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
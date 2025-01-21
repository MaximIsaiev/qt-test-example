#include <thread>
#include <iostream>
#include "concurrentTest.h"

void concurrentTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void concurrentTest::exampleTest()
{
    Concurrent concurrent;
    std::function<void()> printFirst = []()  { std::cout << "1";};
    std::function<void()> printSecond = []()  {std::cout << "2";};
    std::function<void()> printThird = []()  {std::cout << "3";};


    std::thread thread1(&Concurrent::first, &concurrent, printFirst);
    std::thread thread2(&Concurrent::second, &concurrent, printSecond);
    std::thread thread3(&Concurrent::third, &concurrent, printThird);

    thread1.join();
    thread2.join();
    thread3.join();
}


void concurrentTest::cleanupTestCase() {
    qDebug("Called after myFirstTest and mySecondTest.");
}

QTEST_APPLESS_MAIN(concurrentTest)
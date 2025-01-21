#include <thread>
#include <iostream>
#include "concurrentTest.h"

std::string result;

void concurrentTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void concurrentTest::exampleTest1()
{
    Concurrent concurrent;
    result = "";
    std::function<void()> printFirst = []()  {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        result.append("1");
    };
    std::function<void()> printSecond = []()  {result.append("2");};
    std::function<void()> printThird = []()  {result.append("3");};


    std::thread thread1(&Concurrent::first, &concurrent, printFirst);
    std::thread thread2(&Concurrent::second, &concurrent, printSecond);
    std::thread thread3(&Concurrent::third, &concurrent, printThird);

    thread3.join();
    thread2.join();
    thread1.join();

    QCOMPARE(result, std::string{"123"});
}

void concurrentTest::exampleTest2()
{
    Concurrent concurrent;
    result = "";
    std::function<void()> printFirst = []()  {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        result.append("1");
    };
    std::function<void()> printSecond = []()  {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        result.append("2");
    };
    std::function<void()> printThird = []()  {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        result.append("3");
    };


    std::thread thread1(&Concurrent::first, &concurrent, printFirst);
    std::thread thread2(&Concurrent::second, &concurrent, printSecond);
    std::thread thread3(&Concurrent::third, &concurrent, printThird);

    thread1.join();
    thread3.join();
    thread2.join();

    QCOMPARE(result, std::string{"123"});
}

void concurrentTest::exampleTest3()
{
    Concurrent concurrent;
    result = "";
    std::function<void()> printFirst = []()  {result.append("1");};
    std::function<void()> printSecond = []()  {result.append("2");};
    std::function<void()> printThird = []()  {result.append("3");};

    std::thread thread1(&Concurrent::first, &concurrent, printFirst);
    std::thread thread2(&Concurrent::second, &concurrent, printSecond);
    std::thread thread3(&Concurrent::third, &concurrent, printThird);

    thread2.join();
    thread1.join();
    thread3.join();

    QCOMPARE(result, std::string{"123"});
}


void concurrentTest::cleanupTestCase() {
    qDebug("Called after myFirstTest and mySecondTest.");
}

QTEST_APPLESS_MAIN(concurrentTest)
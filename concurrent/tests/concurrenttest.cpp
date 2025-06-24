#include <concurrent.h>
#include <thread>
#include "concurrenttest.h"


void ConcurrentTest::defaultTest()
{
    Concurrent con;
    QString result;
    std::function<void()> first = [&result]()
    {
        result += "first";
    };
    std::function<void()> second = [&result]()
    {
        result += "second";
    };
    std::function<void()> third = [&result]()
    {
        result += "third";
    };
    std::thread a(&Concurrent::first, &con, first);
    std::thread b(&Concurrent::second, &con, second);
    std::thread c(&Concurrent::third, &con, third);
    a.join();
    b.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

void ConcurrentTest::sleepTest1()
{
    Concurrent con;
    QString result;
    std::function<void()> first = [&result]()
    {
        result += "first";
    };
    std::function<void()> second = [&result]()
    {
        result += "second";
    };
    std::function<void()> third = [&result]()
    {
        result += "third";
    };
    std::thread b(&Concurrent::first, &con, first);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread c(&Concurrent::second, &con, second);
    std::thread a(&Concurrent::third, &con, third);
    a.join();
    b.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

void ConcurrentTest::sleepTest2()
{
    Concurrent con;
    QString result;
    std::function<void()> first = [&result]()
    {
        result += "first";
    };
    std::function<void()> second = [&result]()
    {
        result += "second";
    };
    std::function<void()> third = [&result]()
    {
        result += "third";
    };
    std::thread c(&Concurrent::first, &con, first);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread b(&Concurrent::second, &con, second);
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::thread a(&Concurrent::third, &con, third);
    a.join();
    b.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

void ConcurrentTest::sleepTest3()
{
    Concurrent con;
    QString result;
    std::function<void()> first = [&result]()
    {
        result += "first";
    };
    std::function<void()> second = [&result]()
    {
        result += "second";
    };
    std::function<void()> third = [&result]()
    {
        result += "third";
    };
    std::thread c(&Concurrent::first, &con, first);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::thread b(&Concurrent::second, &con, second);
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::thread a(&Concurrent::third, &con, third);
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    a.join();
    b.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

void ConcurrentTest::sleepTest4()
{
    Concurrent con;
    QString result;
    std::function<void()> first = [&result]()
    {
        result += "first";
    };
    std::function<void()> second = [&result]()
    {
        result += "second";
    };
    std::function<void()> third = [&result]()
    {
        result += "third";
    };
    std::thread b(&Concurrent::first, &con, first);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread a(&Concurrent::second, &con, second);
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    std::thread c(&Concurrent::third, &con, third);
    a.join();
    b.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

QTEST_APPLESS_MAIN(ConcurrentTest)

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

void ConcurrentTest::sleepTest()
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
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread b(&Concurrent::second, &con, second);
    std::thread c(&Concurrent::third, &con, third);
    a.join();
    b.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

QTEST_APPLESS_MAIN(ConcurrentTest)

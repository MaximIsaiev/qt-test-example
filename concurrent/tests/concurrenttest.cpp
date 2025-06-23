#include <concurrent.h>
#include <thread>
#include "concurrenttest.h"
#include <iostream>
#include <functional>

void ConcurrentTest::tempTest()
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
    b.join();
    a.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

QTEST_APPLESS_MAIN(ConcurrentTest)

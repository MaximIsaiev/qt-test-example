#include <concurrent.h>
#include <thread>
#include "concurrenttest.h"

void ConcurrentTest::ddtest_data()
{
    QTest::addColumn<std::vector<int>>("order");
    QTest::addColumn<QString>("result");
    QString expectation = "firstsecondthird";

    QTest::addRow("Order: 1, 2, 3") << std::vector<int> {1, 2, 3} << expectation;
    QTest::addRow("Order: 1, 3, 2") << std::vector<int> {1, 3, 2} << expectation;
    QTest::addRow("Order: 2, 1, 3") << std::vector<int> {2, 1, 3} << expectation;
    QTest::addRow("Order: 2, 3, 2") << std::vector<int> {2, 3, 1} << expectation;
    QTest::addRow("Order: 3, 1, 2") << std::vector<int> {3, 1, 2} << expectation;
    QTest::addRow("Order: 3, 2, 1") << std::vector<int> {3, 2, 1} << expectation;
}

void ConcurrentTest::ddtest()
{
    QFETCH(std::vector<int>, order);
    QFETCH(QString, result);
    Concurrent con;
    QString output;
    std::function<void()> first = [&output]()
    {
        output += "first";
    };
    std::function<void()> second = [&output]()
    {
        output += "second";
    };
    std::function<void()> third = [&output]()
    {
        output += "third";
    };
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        if (order[i] == 1) {
            threads.emplace_back(&Concurrent::first, &con, first);
        }
        if (order[i] == 2) {
            threads.emplace_back(&Concurrent::second, &con, second);
        }
        if (order[i] == 3) {
            threads.emplace_back(&Concurrent::third, &con, third);
        }
    }
    for (std::thread &t : threads) {
        t.join();
    }

    QCOMPARE(output, result);
}

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
    std::thread b(&Concurrent::second, &con, second);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread c(&Concurrent::first, &con, first);
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
    std::thread c(&Concurrent::third, &con, third);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread b(&Concurrent::second, &con, second);
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::thread a(&Concurrent::first, &con, first);
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
    std::thread b(&Concurrent::third, &con, third);
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::thread a(&Concurrent::second, &con, second);
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
    std::thread b(&Concurrent::second, &con, second);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::thread a(&Concurrent::third, &con, third);
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    std::thread c(&Concurrent::first, &con, first);
    a.join();
    b.join();
    c.join();

    QCOMPARE("firstsecondthird", result);
}

QTEST_APPLESS_MAIN(ConcurrentTest)

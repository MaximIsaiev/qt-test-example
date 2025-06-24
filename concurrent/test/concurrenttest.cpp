#include "concurrenttest.h"
#include <concurrent.h>

void ConcurrentTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void ConcurrentTest::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest.");
}

void ConcurrentTest::testOrder_data()
{
    QTest::addColumn<std::vector<int>>("order");

    QTest::newRow("1, 2, 3") << std::vector<int> {1, 2, 3};
    QTest::newRow("1, 3, 2") << std::vector<int> {1, 3, 2};
    QTest::newRow("2, 1, 3") << std::vector<int> {2, 1, 3};
    QTest::newRow("2, 3, 1") << std::vector<int> {2, 3, 1};
    QTest::newRow("3, 1, 2") << std::vector<int> {3, 1, 2};
    QTest::newRow("3, 2, 1") << std::vector<int> {3, 2, 1};
}

void ConcurrentTest::testOrder()
{
    QFETCH(std::vector<int>, order);

    std::string result;
    Concurrent foo;

    std::function<void()> printFirst = [&result]() {result += "first";};
    std::function<void()> printSecond = [&result]() {result += "second";};
    std::function<void()> printThird = [&result]() {result += "third";};

    std::vector<std::thread> threads;
    for(int num : order)
    {
        switch(num)
        {
        case 1:
            threads.emplace_back(&Concurrent::first, &foo, printFirst);
            break;
        case 2:
            threads.emplace_back(&Concurrent::second, &foo, printSecond);
            break;
        case 3:
            threads.emplace_back(&Concurrent::third, &foo, printThird);
            break;
        }
    }

    for(auto& thread : threads) thread.join();

    QCOMPARE(QString::fromStdString(result), QString("firstsecondthird"));
}
QTEST_APPLESS_MAIN(ConcurrentTest)

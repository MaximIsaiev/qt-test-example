#include <concurrent.h>
#include "concurrenttest.h"

void ConcurrentTest::initTestCase()
{
    qDebug("Called before everything else.");
}

void ConcurrentTest::cleanupTestCase()
{
    qDebug("Called after last test func was executed.");
}

void ConcurrentTest::testThread(){
    QFETCH(std::vector<int>, order);
    QFETCH(QString, result);
    
    Concurrent concurrent;

    QString output;
    auto printFirst = [&output]() {output += "first";};
    auto printSecond = [&output]() {output += "second";};
    auto printThird = [&output]() {output += "third";};

    std::vector<std::thread> threads;
    
    for(int id : order){
        if(id == 1) {
	    threads.emplace_back(&Concurrent::first, &concurrent, printFirst);
	} else if(id == 2) {
	    threads.emplace_back(&Concurrent::second, &concurrent, printSecond);
	} else if(id == 3) {
	    threads.emplace_back(&Concurrent::third, &concurrent, printThird);
	}
    }

    for(auto &t : threads){
       t.join();
    }

    QCOMPARE(output, result);
}

void ConcurrentTest::testThread_data(){
    QTest::addColumn<std::vector<int>>("order");
    QTest::addColumn<QString>("result");

    QTest::newRow("first_order") << std::vector<int>{1,2,3} << "firstsecondthird";
    QTest::newRow("second_order") << std::vector<int>{2,1,3} << "firstsecondthird";
    QTest::newRow("third_order") << std::vector<int>{3,2,1} << "firstsecondthird";
}
QTEST_APPLESS_MAIN(ConcurrentTest)

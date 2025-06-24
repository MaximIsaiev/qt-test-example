#pragma once
#include <QtTest/QTest>

class ConcurrentTest : public QObject
{
    Q_OBJECT

private slots:
    void ddtest_data();
    void ddtest();

    void defaultTest();
    void sleepTest1();
    void sleepTest2();
    void sleepTest3();
    void sleepTest4();
};


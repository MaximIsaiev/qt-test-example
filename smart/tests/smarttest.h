#pragma once
#include <QtTest/QTest>
class SmartTest: public QObject
{
    Q_OBJECT
private slots:
    void tableTest_data();
    void tableTest();

    void test1();
    void pushBackTest();
    void highIntTest();
    void negativeIntTest();
    void bigArrayTest();
};

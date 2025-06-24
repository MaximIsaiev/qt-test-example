#pragma once
#include <QtTest/QTest>

class SmartTest: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void exampleTest();
    void cleanupTestCase();
    void threeConsecutiveOdds_data();
    void threeConsecutiveOdds();
    void test1();
};

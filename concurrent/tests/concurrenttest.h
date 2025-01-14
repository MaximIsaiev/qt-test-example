#pragma once
#include <QtTest/QTest>
#include <thread>
#include <QString>
class ConcurrentTest: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testThread();
    void testThread_data();
};

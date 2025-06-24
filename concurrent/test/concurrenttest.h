#pragma once
#include <QtTest/QTest>
#include <thread>

class ConcurrentTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testOrder();
    void testOrder_data();
};

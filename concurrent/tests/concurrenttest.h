#pragma once
#include <QtTest/QTest>

class ConcurrentTest : public QObject
{
    Q_OBJECT

private slots:
    void defaultTest();
    void sleepTest();
};


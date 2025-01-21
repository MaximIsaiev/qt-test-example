#ifndef QTTESTEXAMPLE_CONCURRENTTEST_H
#define QTTESTEXAMPLE_CONCURRENTTEST_H

#pragma once
#include <QtTest/QTest>
#include "concurrent.h"


class concurrentTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void exampleTest1();
    void exampleTest2();
    void exampleTest3();
    void cleanupTestCase();
};

#endif //QTTESTEXAMPLE_CONCURRENTTEST_H

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
    int startThreads(const std::vector<int>&);
    void tableTest_data();
    void tableTest();
    void cleanupTestCase();
};

#endif //QTTESTEXAMPLE_CONCURRENTTEST_H

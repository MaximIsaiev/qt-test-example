#pragma once
#include <QtTest/QTest>
class SmartTest: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void threeConsecutiveOddsWithOnlyEven();
    void threeConsecutiveOddsWithThreeOdds();
    void threeConsecutiveOddsWithOnlyZeros();
    void threeConsecutiveOddsWithThreeNegativeOdds();
    void threeConsecutiveOddsWithNan();
    void threeConsecutiveOdds_data();
    void threeConsecutiveOdds();
    
    void cleanupTestCase();
};

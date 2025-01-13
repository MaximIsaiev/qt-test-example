#pragma once
#include <QObject>
#include <vector>
#include "smartlib_export.h"
#include <cmath>
class SMARTLIB_EXPORT Smart : public QObject
{
    Q_OBJECT
public:
    explicit Smart(QObject *parent = nullptr);
    ~Smart() override;

    static bool threeConsecutiveOdds(std::vector<int> &arr);
    static bool threeConsecutiveOdds(std::vector<double> &arr);
};

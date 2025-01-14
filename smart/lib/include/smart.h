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
    template <typename T>
    static bool threeConsecutiveOdds(std::vector<T>& arr);
};

template <typename T>
bool Smart::threeConsecutiveOdds(std::vector<T>& arr){
    int count = 0;
    bool flag = false;
    for (const auto &val : arr){
	    if (std::abs(std::lround(val)) % 2 == 1)
		count++;
	    else
		count = 0;

	    if (count == 3)
		flag = true;
    }
    return flag;
}

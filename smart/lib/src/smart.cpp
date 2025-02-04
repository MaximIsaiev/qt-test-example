#include "smart.h"

bool Smart::threeConsecutiveOdds(std::vector<int> &arr)
{
    int count = 0;
    for (const auto &val : arr) {
        if (val % 2 == 1)
            count++;
        else
            count = 0;

        if (count == 3)
            return true;
    }

    return false;
}

Smart::Smart(QObject *parent) :
    QObject(parent)
{

}

Smart::~Smart() = default;

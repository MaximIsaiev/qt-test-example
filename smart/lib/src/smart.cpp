#include "smart.h"

int absolute(int value)
{
    if(value < 0) {
        value *= -1;
    }
    return value;
}


bool Smart::threeConsecutiveOdds(std::vector<int> &arr)
{
    int count = 0;
    for (const int &val : arr) {
        if (absolute(val) % 2 == 1)
            count++;
        else
            count = 0;

        if (count == 3)
            return true;
    }

    return false;
}



Smart::Smart(QObject *parent) : QObject(parent)
{

}

Smart::~Smart() = default;

#include "concurrent.h"
#include <iostream>
#include <functional>
void Concurrent::first(std::function<void()> printFirst)
{
    std::lock_guard<std::mutex> lock(firstMutex);
    printFirst();
    firstReady = true;
    cv.notify_all();
}

void Concurrent::second(std::function<void()> printSecond)
{
    std::unique_lock<std::mutex> lock(firstMutex);
    cv.wait(
        lock,
        [this]
        {
            return firstReady;
        }
    );
    std::lock_guard<std::mutex> lock2(secondMutex);
    printSecond();
    secondReady = true;
    cv.notify_all();
}

void Concurrent::third(std::function<void()> printThird)
{
    std::unique_lock<std::mutex> lock(secondMutex);
    cv.wait(
        lock,
        [this]
        {
            return secondReady;
        }
    );
    printThird();
}

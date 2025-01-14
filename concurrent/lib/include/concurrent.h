#pragma once
#include <condition_variable>
#include <functional>
#include <mutex>

class Concurrent
{
public:
    void first(std::function<void()> printFirst);
    void second(std::function<void()> printSecond);
    void third(std::function<void()> printThird);

private:
    std::mutex firstMutex;
    std::mutex secondMutex;
    std::condition_variable cv;
    bool firstReady {false};
    bool secondReady {false};
};

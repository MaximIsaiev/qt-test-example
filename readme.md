## Задача 1

Необходимо протестировать класс _Smart_ с помощью _Qt_. Класс _Smart_ реализует решение задачи __1550. Three Consecutive Odds__ с сайта LeetCode.com. \
\
Класс для тестирования уже есть, он называется _SmartTest_.\
\
Для решения задачи необходимо воспользоваться макросами _QCOMAPE_, _QVERIFY_ и _QFETCH_. 

## Описание задачи класса Smart

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

* _Example 1_:

__Input__: arr = [2,6,4,1]\
__Output__: false\
__Explanation__: There are no three consecutive odds.

* _Example 2_:

__Input__: arr = [1,2,34,3,4,5,7,23,12]\
__Output__: true\
__Explanation__: [5,7,23] are three consecutive odds.

## Задача 2

Необходимо протестировать класс _Concurrent_ с помощью _Qt_. Класс _Concurrent_ реализует решение задачи __1114. Print in Order__ с сайта LeetCode.com.\
\
Класса для тестирования __нет__, его необходимо самостоятельно добавить как отдельный таргет (по аналогии со _SmartTest_)\
\
Для решения задачи необходимо воспользоваться _std::thread_ и _std::function_, а также макросами _QCOMAPE_, _QVERIFY_ и _QFETCH_. 

## Описание задачи класса Concurrent

Suppose we have a class:

```c++
public class Foo 
{
public void first() { print("first"); }
public void second() { print("second"); }
public void third() { print("third"); }
}
```


The same instance of _Foo_ will be passed to three different threads. Thread A will call _first()_, thread B will call _second()_, and thread C will call _third()_. Design a mechanism and modify the program to ensure that _second()_ is executed after _first()_, and _third()_ is executed after _second()_.
\
\
Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.



Example 1:

**Input**: nums = [1,2,3]\
**Output**: "firstsecondthird"\
**Explanation**: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls _first()_, thread B calls _second()_, and thread C calls _third()_. "firstsecondthird" is the correct output.\
\
Example 2:

**Input**: nums = [1,3,2]\
**Output**: "firstsecondthird"\
**Explanation**: The input [1,3,2] means thread A calls _first()_, thread B calls _third()_, and thread C calls _second()_. "firstsecondthird" is the correct output.

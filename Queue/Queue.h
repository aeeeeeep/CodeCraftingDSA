#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:

public:
    // 构造函数
    Queue() {}

    // 析构函数
    virtual ~Queue() {}

    // 入队操作
    virtual void EnQueue(const T& e) = 0;

    // 出队操作
    virtual void DeQueue(T& e) = 0;

    // 读队头操作
    virtual int GetHead(T& e) = 0;

    // 判空操作
    virtual bool Empty() = 0;
};

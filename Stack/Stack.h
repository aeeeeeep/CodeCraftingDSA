#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:

public:
    // 构造函数
    Stack() {}

    // 析构函数
    virtual ~Stack() {}

    // 入栈操作
    virtual void Push(const T& e) = 0;

    // 出栈操作
    virtual void Pop(T& e) = 0;

    // 读栈顶操作
    virtual int GetTop() = 0;

    // 判空操作
    virtual bool Empty() = 0;
};

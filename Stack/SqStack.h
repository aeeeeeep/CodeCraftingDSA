#pragma once
#include <iostream>
#include "Stack.h"

using namespace std;

template <typename T>
class SqStack : public Stack<T> {
private:
    static const int MAX_SIZE = 100;  // 栈的最大容量
    T data[MAX_SIZE];  // 栈的存储空间
    int top;           // 栈顶指针

public:
    // 构造函数
    SqStack() {
        top = -1;
    }

    // 析构函数
    ~SqStack() {}

    // 入栈操作
    void Push(const T& e) {
        if (top == MAX_SIZE - 1) {
            cout << "栈已满，无法执行入栈操作！" << endl;
            return;
        }
        top++;
        data[top] = e;
    }

    // 出栈操作
    void Pop(T& e) {
        if (top == -1) {
            cout << "栈为空，无法执行出栈操作！" << endl;
            return;
        }
        e = data[top];
        top--;
    }

    // 读栈顶操作
    int GetTop() {
        if (top == -1) {
            cout << "栈为空，无法读取栈顶元素！" << endl;
            return -1;
        }
        return data[top];
    }

    // 判空操作
    bool Empty() {
        return (top == -1);
    }
};

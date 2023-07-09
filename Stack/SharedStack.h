#pragma once
#include <iostream>
#include "SqStack.h"

using namespace std;

template <typename T>
class SharedStack {
private:
    static const int MAX_SIZE = 100;  // 栈的最大容量
    T data[MAX_SIZE];  // 栈的存储空间
    int top[2];        // 两个栈的栈顶指针

public:
    // 构造函数
    SharedStack() {
        top[0] = -1;
        top[1] = MAX_SIZE;
    }

    // 析构函数
    ~SharedStack() {}

    // 入栈操作
    void Push(int stackNumber, const T& e) {
        if (stackNumber != 0 && stackNumber != 1) {
            cout << "无效的栈编号！" << endl;
            return;
        }

        if (top[0] + 1 == top[1]) {
            cout << "栈已满，无法执行入栈操作！" << endl;
            return;
        }

        if (stackNumber == 0) {
            top[0]++;
            data[top[0]] = e;
        } else {
            top[1]--;
            data[top[1]] = e;
        }
    }

    // 出栈操作
    void Pop(int stackNumber, T& e) {
        if (stackNumber != 0 && stackNumber != 1) {
            cout << "无效的栈编号！" << endl;
            return;
        }

        if (stackNumber == 0) {
            if (top[0] == -1) {
                cout << "栈" << stackNumber << "为空，无法执行出栈操作！" << endl;
                return;
            }
            e = data[top[0]];
            top[0]--;
        } else {
            if (top[1] == MAX_SIZE) {
                cout << "栈" << stackNumber << "为空，无法执行出栈操作！" << endl;
                return;
            }
            e = data[top[1]];
            top[1]++;
        }
    }

    // 读栈顶操作
    T GetTop(int stackNumber) {
        if (stackNumber != 0 && stackNumber != 1) {
            cout << "无效的栈编号！" << endl;
            return -1;
        }

        if (stackNumber == 0) {
            if (top[0] == -1) {
                cout << "栈" << stackNumber << "为空，无法读取栈顶元素！" << endl;
                return -1;
            }
            return data[top[0]];
        } else {
            if (top[1] == MAX_SIZE) {
                cout << "栈" << stackNumber << "为空，无法读取栈顶元素！" << endl;
                return -1;
            }
            return data[top[1]];
        }
    }

    // 判空操作
    bool Empty(int stackNumber) {
        if (stackNumber != 0 && stackNumber != 1) {
            cout << "无效的栈编号！" << endl;
            return false;
        }

        if (stackNumber == 0) {
            return (top[0] == -1);
        } else {
            return (top[1] == MAX_SIZE);
        }
    }
};

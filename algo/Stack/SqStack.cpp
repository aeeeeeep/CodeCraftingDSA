#include <iostream>
#include "Stack.h"
const int MAX_SIZE = 100;  // 栈的最大容量

using namespace std;

template <typename T>
class SqStack : public Stack<T> {
private:
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
    int GetTop(T& e) {
        if (top == -1) {
            cout << "栈为空，无法读取栈顶元素！" << endl;
            return -1;
        }
        e = data[top];
        return 0;
    }

    // 判空操作
    bool Empty() {
        return (top == -1);
    }
};

int main() {
    SqStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    int topElement;
    stack.GetTop(topElement);
    cout << "栈顶元素为: " << topElement << endl;

    int poppedElement;
    stack.Pop(poppedElement);
    cout << "出栈元素为: " << poppedElement << endl;
    stack.Pop(poppedElement);
    cout << "出栈元素为: " << poppedElement << endl;
    stack.Pop(poppedElement);
    cout << "出栈元素为: " << poppedElement << endl;

    cout << stack.GetTop(topElement) << endl;
    if (stack.Empty()) {
        cout << "栈为空" << endl;
    } else {
        cout << "栈非空" << endl;
    }

    return 0;
}

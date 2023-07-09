#include <iostream>
#include "Stack.h"
using namespace std;

template <typename T>
class LinkStack : public Stack<T> {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;  // 栈顶指针

public:
    // 构造函数
    LinkStack() {
        top = nullptr;
    }

    // 析构函数
    ~LinkStack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // 入栈操作
    void Push(const T& e) {
        Node* newNode = new Node;
        newNode->data = e;
        newNode->next = top;
        top = newNode;
    }

    // 出栈操作
    void Pop(T& e) {
        if (top == nullptr) {
            cout << "栈为空，无法执行出栈操作！" << endl;
            return;
        }
        e = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // 读栈顶操作
    int GetTop() {
        if (top == nullptr) {
            cout << "栈为空，无法读取栈顶元素！" << endl;
            return -1;
        }
        return top->data;
    }

    // 判空操作
    bool Empty() {
        return (top == nullptr);
    }
};


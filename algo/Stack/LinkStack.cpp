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
    int GetTop(T& e) {
        if (top == nullptr) {
            cout << "栈为空，无法读取栈顶元素！" << endl;
            return -1;
        }
        e = top->data;
        return 0;
    }

    // 判空操作
    bool Empty() {
        return (top == nullptr);
    }
};

int main() {
    LinkStack<int> stack;
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

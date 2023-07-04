#include "SharedStack.h"

int main() {
    SharedStack<int> stack;

    // 入栈操作
    stack.Push(0, 1);  // 向栈0入栈元素1
    stack.Push(1, 2);  // 向栈1入栈元素2
    stack.Push(0, 3);  // 向栈0入栈元素3
    stack.Push(1, 4);  // 向栈1入栈元素4

    // 读取栈顶元素
    cout << "栈0的栈顶元素: " << stack.GetTop(0) << endl;
    cout << "栈1的栈顶元素: " << stack.GetTop(1) << endl;

    // 出栈操作
    int poppedElement;
    stack.Pop(0, poppedElement);  // 从栈0出栈
    cout << "从栈0出栈的元素: " << poppedElement << endl;
    stack.Pop(1, poppedElement);  // 从栈1出栈
    cout << "从栈1出栈的元素: " << poppedElement << endl;

    // 判空操作
    cout << "栈0是否为空: " << (stack.Empty(0) ? "是" : "否") << endl;
    cout << "栈1是否为空: " << (stack.Empty(1) ? "是" : "否") << endl;

    return 0;
}


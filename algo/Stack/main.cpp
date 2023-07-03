#include "LinkStack.h"

int main() {
    LinkStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    int topElement = stack.GetTop();
    cout << "栈顶元素为: " << topElement << endl;

    int poppedElement;
    stack.Pop(poppedElement);
    cout << "出栈元素为: " << poppedElement << endl;
    stack.Pop(poppedElement);
    cout << "出栈元素为: " << poppedElement << endl;
    stack.Pop(poppedElement);
    cout << "出栈元素为: " << poppedElement << endl;

    cout << stack.GetTop() << endl;
    if (stack.Empty()) {
        cout << "栈为空" << endl;
    } else {
        cout << "栈非空" << endl;
    }

    return 0;
}

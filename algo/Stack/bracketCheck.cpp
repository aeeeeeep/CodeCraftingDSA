#include "LinkStack.h"
using namespace std;

bool isBracketMatched(const string& expression) {
    LinkStack<char> stack;
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.Push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char top = stack.GetTop();
            if (top != -1) {
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')) {
                    stack.Pop(top);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return stack.Empty();
}

int main() {
    string expression;
    cout << "请输入一个包含括号的表达式：";
    getline(cin, expression);

    if (isBracketMatched(expression)) {
        cout << "括号匹配正确！" << endl;
    } else {
        cout << "括号匹配错误！" << endl;
    }

    return 0;
}

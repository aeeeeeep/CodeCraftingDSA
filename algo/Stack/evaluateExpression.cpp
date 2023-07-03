#include <iostream>
#include <algorithm>
#include "LinkStack.h" // 包含前面定义的链式栈

using namespace std;

// 判断字符是否为运算符
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// 获取运算符的优先级
int getPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // 如果是其他字符，返回0，优先级最低
}

// 中缀表达式转逆波兰表达式
string infixToPostfix(const string& infixExpr) {
    string postfixExpr; // 存放逆波兰表达式的字符串
    LinkStack<char> operatorStack; // 运算符栈

    for (size_t i = 0; i < infixExpr.length(); ++i) {
        char ch = infixExpr[i];
        if (isdigit(ch)) {
            // 如果是数字，直接加入到逆波兰表达式中
            postfixExpr += ch;
        } else if (isOperator(ch)) {
            // 如果是运算符，弹出优先级大于或等于当前运算符的运算符，并加入到逆波兰表达式中
            while (!operatorStack.Empty() && isOperator(operatorStack.GetTop()) &&
                   getPriority(ch) <= getPriority(operatorStack.GetTop())) {
                char op;
                operatorStack.Pop(op);
                postfixExpr += op;
            }
            operatorStack.Push(ch);
        } else if (ch == '(') {
            // 如果是左括号，直接入栈
            operatorStack.Push(ch);
        } else if (ch == ')') {
            // 如果是右括号，弹出运算符直到遇到左括号，并加入到逆波兰表达式中
            while (!operatorStack.Empty() && operatorStack.GetTop() != '(') {
                char op;
                operatorStack.Pop(op);
                postfixExpr += op;
            }
            operatorStack.Pop(ch); // 弹出左括号
        }
    }

    // 将剩余的运算符弹出并加入到逆波兰表达式中
    while (!operatorStack.Empty()) {
        char op;
        operatorStack.Pop(op);
        postfixExpr += op;
    }

    return postfixExpr;
}

// 计算逆波兰表达式
int evaluatePostfix(const string& postfixExpr) {
    LinkStack<int> operandStack; // 操作数栈

    for (size_t i = 0; i < postfixExpr.length(); ++i) {
        char ch = postfixExpr[i];
        if (isdigit(ch)) {
            // 如果是数字，转换为整数并入栈
            int num = ch - '0';
            operandStack.Push(num);
        } else if (isOperator(ch)) {
            // 如果是运算符，从栈中弹出两个操作数进行计算，结果再入栈
            int operand2, operand1;
            operandStack.Pop(operand2);
            operandStack.Pop(operand1);
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            operandStack.Push(result);
        }
    }

    // 最终栈中剩下的操作数就是计算结果
    int result;
    operandStack.Pop(result);
    return result;
}

// 中缀表达式转波兰表达式
string infixToPrefix(const string& infixExpr) {
    string prefixExpr; // 存放波兰表达式的字符串
    LinkStack<char> operatorStack; // 运算符栈

    // 将中缀表达式反转
    string reversedInfix = infixExpr;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (size_t i = 0; i < reversedInfix.length(); ++i) {
        char ch = reversedInfix[i];
        if (isdigit(ch)) {
            // 如果是数字，直接加入到波兰表达式中
            prefixExpr += ch;
        } else if (isOperator(ch)) {
            // 如果是运算符，弹出优先级大于或等于当前运算符的运算符，并加入到波兰表达式中
            while (!operatorStack.Empty() && isOperator(operatorStack.GetTop()) &&
                   getPriority(ch) < getPriority(operatorStack.GetTop())) {
                char op;
                operatorStack.Pop(op);
                prefixExpr += op;
            }
            operatorStack.Push(ch);
        } else if (ch == ')') {
            // 如果是右括号，直接入栈
            operatorStack.Push(ch);
        } else if (ch == '(') {
            // 如果是左括号，弹出运算符直到遇到右括号，并加入到波兰表达式中
            while (!operatorStack.Empty() && operatorStack.GetTop() != ')') {
                char op;
                operatorStack.Pop(op);
                prefixExpr += op;
            }
            operatorStack.Pop(ch); // 弹出右括号
        }
    }

    // 将剩余的运算符弹出并加入到波兰表达式中
    while (!operatorStack.Empty()) {
        char op;
        operatorStack.Pop(op);
        prefixExpr += op;
    }

    // 将波兰表达式再次反转，得到最终的前缀表达式
    reverse(prefixExpr.begin(), prefixExpr.end());
    return prefixExpr;
}

// 计算前缀表达式
int evaluatePrefix(const string& prefixExpr) {
    LinkStack<int> operandStack; // 操作数栈

    // 将前缀表达式反转
    string reversedPrefix = prefixExpr;
    reverse(reversedPrefix.begin(), reversedPrefix.end());

    for (size_t i = 0; i < reversedPrefix.length(); ++i) {
        char ch = reversedPrefix[i];
        if (isdigit(ch)) {
            // 如果是数字，转换为整数并入栈
            int num = ch - '0';
            operandStack.Push(num);
        } else if (isOperator(ch)) {
            // 如果是运算符，从栈中弹出两个操作数进行计算，结果再入栈
            int operand1, operand2;
            operandStack.Pop(operand1);
            operandStack.Pop(operand2);
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            operandStack.Push(result);
        }
    }

    // 最终栈中剩下的操作数就是计算结果
    int result;
    operandStack.Pop(result);
    return result;
}

int main() {
    string infixExpr;
    cout << "请输入中缀表达式：";
    getline(cin, infixExpr);

    string postfixExpr = infixToPostfix(infixExpr);
    cout << "逆波兰表达式：" << postfixExpr << endl;

    int postfixResult = evaluatePostfix(postfixExpr);
    cout << "逆波兰表达式计算结果：" << postfixResult << endl;

    string prefixExpr = infixToPrefix(infixExpr);
    cout << "波兰表达式：" << prefixExpr << endl;

    int prefixResult = evaluatePrefix(prefixExpr);
    cout << "波兰表达式计算结果：" << prefixResult << endl;

    return 0;
}

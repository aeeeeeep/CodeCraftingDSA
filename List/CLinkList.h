#pragma once
#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
class CLinkList : public List<T> {
private:
    struct CNode {
        T data;
        CNode *next;
    };

    CNode *head;  // 头指针

public:
    // 构造函数
    CLinkList() {
        head = new CNode();
        head->next = head;
    }

    // 析构函数
    ~CLinkList() {
        Clear();
        delete head;
    }

    // 清空链表
    void Clear() {
        CNode *current = head->next;
        while (current != head) {
            CNode *next = current->next;
            delete current;
            current = next;
        }
        head->next = head;
    }

    // 重载[]运算符为GetElem函数操作
    T &operator[](int i) {
        CNode *current = head->next;
        for (int j = 0; j < i - 1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 插入操作
    void Insert(int i, const T &e) {
        CNode *newCNode = new CNode();
        newCNode->data = e;

        if (i == 1) {
            newCNode->next = head->next;
            head->next = newCNode;
        } else {
            CNode *current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->next;
            }
            newCNode->next = current->next;
            current->next = newCNode;
        }
    }

    // 删除操作
    void Delete(int i, T &e) {
        if (i == 1) {
            CNode *temp = head->next;
            e = temp->data;
            head->next = temp->next;
            delete temp;
        } else {
            CNode *current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->next;
            }
            CNode *temp = current->next;
            e = temp->data;
            current->next = temp->next;
            delete temp;
        }
    }

    // 按值查找操作
    int LocateElem(const T &e) {
        CNode *current = head->next;
        int i = 1;
        while (current != head) {
            if (current->data == e) {
                return i;
            }
            current = current->next;
            i++;
        }
        return -1;  // 未找到元素
    }

    // 按位查找操作
    T GetElem(int i) {
        CNode *current = head->next;
        for (int j = 0; j < i - 1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 求表长
    int Length() {
        int length = 0;
        CNode *current = head->next;
        while (current != head) {
            length++;
            current = current->next;
        }
        return length;
    }

    // 输出操作
    void Print() {
        CNode *current = head->next;
        while (current != head) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 判空操作
    bool Empty() {
        return head->next == head;
    }
};

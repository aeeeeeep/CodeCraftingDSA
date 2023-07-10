#pragma once
#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
class LinkList : public List<T> {
private:
    static const int MAX_SIZE = 100;  // 最大容量
    struct Node {
        T data;
        int next;
    };

    Node nodes[MAX_SIZE];  // 静态链表节点数组
    int length;  // 链表长度
    int head;  // 头节点位置
    int free;  // 空闲节点位置

public:
    // 构造函数
    LinkList() {
        length = 0;
        head = -1;
        free = 0;
        for (int i = 0; i < MAX_SIZE - 1; i++) {
            nodes[i].next = i + 1;
        }
        nodes[MAX_SIZE - 1].next = -1;  // 最后一个节点的next为-1表示链表结束
    }

    ~LinkList() {
        Clear();
    }

    // 清空链表
    void Clear() {
        length = 0;
        head = -1;
        free = 0;
        for (int i = 0; i < MAX_SIZE - 1; i++) {
            nodes[i].next = i + 1;
        }
        nodes[MAX_SIZE - 1].next = -1;
    }

    // 重载[]运算符为GetElem函数操作
    T &operator[](int i) {
        int p = head;
        for (int j = 0; j < i - 1; j++) {
            p = nodes[p].next;
        }
        return nodes[p].data;
    }

    // 插入操作
    void Insert(int i, const T &e) {
        if (i < 1 || i > length + 1) {
            cout << "插入位置不合法" << endl;
            return;
        }
        if (free == -1) {
            cout << "链表已满，无法插入" << endl;
            return;
        }

        int p = head;
        int q = free;
        free = nodes[free].next;
        nodes[q].data = e;

        if (i == 1) {
            nodes[q].next = head;
            head = q;
        } else {
            for (int j = 0; j < i - 2; j++) {
                p = nodes[p].next;
            }
            nodes[q].next = nodes[p].next;
            nodes[p].next = q;
        }
        length++;
    }

    // 删除操作
    void Delete(int i, T &e) {
        if (i < 1 || i > length) {
            cout << "删除位置不合法" << endl;
            return;
        }

        int p = head;
        int q;
        if (i == 1) {
            head = nodes[head].next;
            q = p;
        } else {
            for (int j = 0; j < i - 2; j++) {
                p = nodes[p].next;
            }
            q = nodes[p].next;
            nodes[p].next = nodes[q].next;
        }
        e = nodes[q].data;
        nodes[q].next = free;
        free = q;
        length--;
    }

    // 按值查找操作
    int LocateElem(const T &e) {
        int p = head;
        int i = 1;
        while (p != -1 && nodes[p].data != e) {
            p = nodes[p].next;
            i++;
        }
        if (p == -1) {
            return 0;  // 未找到
        } else {
            return i;  // 返回位置
        }
    }

    // 按位查找操作
    T GetElem(int i) {
        if (i < 1 || i > length) {
            cout << "位置不合法" << endl;
            exit(1);
        }

        int p = head;
        for (int j = 0; j < i - 1; j++) {
            p = nodes[p].next;
        }
        return nodes[p].data;
    }

    // 求表长
    int Length() {
        return length;
    }

    // 输出操作
    void Print() {
        int p = head;
        while (p != -1) {
            cout << nodes[p].data << " ";
            p = nodes[p].next;
        }
        cout << endl;
    }

    // 判空操作
    bool Empty() {
        return length == 0;
    }
};

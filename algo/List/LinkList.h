#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class LinkList : public List<T> {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;  // 头指针

public:
    // 构造函数
    LinkList() {
        head = new Node();
        head->next = nullptr;
    }

    // 析构函数
    ~LinkList() {
        Clear();
    }

    // 清空链表
    void Clear() {
        Node* current = head->next;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // 重载[]运算符为GetElem函数操作
    T& operator[](int i) {
        Node* current = head->next;
        for (int j = 0; j < i-1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 插入操作
    void Insert(int i, const T& e) {
        Node* newNode = new Node();
        newNode->data = e;

        if (i == 1) {
            newNode->next = head->next;
            head->next = newNode;
        } else {
            Node* current = head;
            for (int j = 0; j < i-1; j++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // 删除操作
    void Delete(int i, T& e) {
        if (i == 1) {
            Node* temp = head;
            e = temp->data;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int j = 0; j < i-1; j++) {
                current = current->next;
            }
            Node* temp = current->next;
            e = temp->data;
            current->next = temp->next;
            delete temp;
        }
    }

    // 按值查找操作
    int LocateElem(const T& e) {
        Node* current = head->next;
        int i = 1;
        while (current != nullptr) {
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
        Node* current = head->next;
        for (int j = 0; j < i-1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 求表长
    int Length() {
        int length = 0;
        Node* current = head->next;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // 输出操作
    void Print() {
        Node* current = head->next;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 判空操作
    bool Empty() {
        return head == nullptr;
    }
};

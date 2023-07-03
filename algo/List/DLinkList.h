#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class DLinkList : public List<T> {
private:
    struct DNode {
        T data;
        DNode* prev;
        DNode* next;
    };

    DNode* head;  // 头指针

public:
    // 构造函数
    DLinkList() {
        head = new DNode();
        head->next = nullptr;
    }

    // 析构函数
    ~DLinkList() {
        Clear();
    }

    // 清空链表
    void Clear() {
        DNode* current = head->next;
        while (current != nullptr) {
            DNode* next = current->next;
            delete current;
            current = next;
        }
    }

    // 重载[]运算符为GetElem函数操作
    T& operator[](int i) {
        DNode* current = head->next;
        for (int j = 0; j < i-1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 插入操作
    void Insert(int i, const T& e) {
        DNode* newDNode = new DNode();
        newDNode->data = e;

        if (i == 1) {
            newDNode->prev = head;
            newDNode->next = head->next;
            head->prev = nullptr;
            head->next = newDNode;
        } else {
            DNode* current = head;
            for (int j = 0; j < i-1; j++) {
                current = current->next;
            }
            newDNode->prev = current;
            newDNode->next = current->next;
            current->next = newDNode;
        }
    }

    // 删除操作
    void Delete(int i, T& e) {
        if (i == 1) {
            DNode* temp = head->next;
            e = temp->data;
            head->prev = nullptr;
            delete temp;
        } else {
            DNode* current = head;
            for (int j = 0; j < i-1; j++) {
                current = current->next;
            }
            DNode* temp = current->next;
            e = temp->data;
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            delete temp;
        }
    }

    // 按值查找操作
    int LocateElem(const T& e) {
        DNode* current = head->next;
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
        DNode* current = head->next;
        for (int j = 0; j < i-1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 求表长
    int Length() {
        int length = 0;
        DNode* current = head->next;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // 输出操作
    void Print() {
        DNode* current = head->next;
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

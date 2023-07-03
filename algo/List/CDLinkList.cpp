#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class CDLinkList : public List<T> {
private:
    struct CDNode {
        T data;
        CDNode* prev;
        CDNode* next;
    };

    CDNode* head;  // 头指针

public:
    // 构造函数
    CDLinkList() {
        head = new CDNode();
        head->next = head;
        head->prev = head;
    }

    // 析构函数
    ~CDLinkList() {
        Clear();
    }

    // 清空链表
    void Clear() {
        CDNode* current = head->next;
        while (current != head) {
            CDNode* next = current->next;
            delete current;
            current = next;
        }
        head->next = head;
        head->prev = head;
    }

    // 重载[]运算符为GetElem函数操作
    T& operator[](int i) {
        CDNode* current = head->next;
        for (int j = 0; j < i-1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 插入操作
    void Insert(int i, const T& e) {
        CDNode* newCDNode = new CDNode();
        newCDNode->data = e;

        if (i == 1) {
            newCDNode->prev = head;
            newCDNode->next = head->next;
            head->prev = nullptr;
            head->next = newCDNode;
        } else {
            CDNode* current = head;
            for (int j = 0; j < i-1; j++) {
                current = current->next;
            }
            newCDNode->prev = current;
            newCDNode->next = current->next;
            current->next = newCDNode;
        }
    }

    // 删除操作
    void Delete(int i, T& e) {
        if (i == 1) {
            CDNode* temp = head->next;
            e = temp->data;
            head->next = temp->next;
            temp->next->prev = head;
            delete temp;
        } else {
            CDNode* current = head;
            for (int j = 0; j < i-1; j++) {
                current = current->next;
            }
            CDNode* temp = current->next;
            e = temp->data;
            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
        }
    }

    // 按值查找操作
    int LocateElem(const T& e) {
        CDNode* current = head->next;
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
        CDNode* current = head->next;
        for (int j = 0; j < i-1; j++) {
            current = current->next;
        }
        return current->data;
    }

    // 求表长
    int Length() {
        int length = 0;
        CDNode* current = head->next;
        while (current != head) {
            length++;
            current = current->next;
        }
        return length;
    }

    // 输出操作
    void Print() {
        CDNode* current = head->next;
        while (current != head) {
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

int main() {
    CDLinkList<int> L;
    L.Insert(1, 10);
    L.Insert(2, 20);
    L.Insert(3, 30);
    L.Insert(4, 40);
    L.Print(); // 输出: 10 20 30
    int e;
    L.Delete(4, e);
    cout << "删除的元素为: " << e << endl; // 输出: 删除的元素为: 20
    cout << "表长为: " << L.Length() << endl; // 输出: 表长为: 2
    cout << "第一个元素为: " << L[1] << endl; // 输出: 第一个元素为: 10
    cout << "元素30的位置为: " << L.LocateElem(30) << endl; // 输出: 元素30的位置为: 2
    L.Print();
    cout << "是否为空表: " << (L.Empty() ? "是" : "否") << endl; // 输出: 是否为空表: 否

    return 0;
}

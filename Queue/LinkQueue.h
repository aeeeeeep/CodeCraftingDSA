#pragma once
#include <iostream>
#include "Queue.h"

template <typename T>
class LinkQueue : public Queue<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;  // 队头指针
    Node* rear;   // 队尾指针

public:
    // 构造函数
    LinkQueue() : front(nullptr), rear(nullptr) {}

    // 析构函数
    ~LinkQueue() {
        Node* current = front;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // 入队操作
    void EnQueue(const T& e) {
        Node* newNode = new Node(e);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // 出队操作
    void DeQueue(T& e) {
        if (front == nullptr) {
            cout << "队列为空" << endl;
            return;
        }
        Node* temp = front;
        e = front->data;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // 读队头操作
    int GetHead(T& e) {
        if (front == nullptr) {
            cout << "队列为空" << endl;
            return -1;
        }
        e = front->data;
        return 0;
    }

    // 判空操作
    bool Empty() {
        return (front == nullptr);
    }
};

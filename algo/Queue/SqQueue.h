#include <iostream>
#include "Queue.h"

template <typename T>
class SqQueue : public Queue<T> {
private:
    static const int MAX_SIZE = 100; // 队列的最大容量
    T data[MAX_SIZE]; // 存储元素的数组
    int front; // 队头指针
    int rear; // 队尾指针

public:
    // 构造函数
    SqQueue() {
        front = rear = 0; // 初始化队头和队尾指针为0
    }

    // 析构函数
    ~SqQueue() {}

    // 入队操作
    void EnQueue(const T& e) {
        if ((rear + 1) % MAX_SIZE == front) {
            cout << "队列已满" << endl;
            return;
        }
        data[rear] = e; // 将元素存入队尾
        rear = (rear + 1) % MAX_SIZE; // 更新队尾指针
    }

    // 出队操作
    void DeQueue(T& e) {
        if (front == rear) {
            cout << "队列为空" << endl;
            return;
        }
        e = data[front]; // 将队头元素取出
        front = (front + 1) % MAX_SIZE; // 更新队头指针
    }

    // 读队头操作
    int GetHead(T& e) {
        if (front == rear) {
            cout << "队列为空" << endl;
            return -1;
        }
        e = data[front]; // 读取队头元素
        return 0;
    }

    // 判空操作
    bool Empty() {
        return front == rear;
    }
};

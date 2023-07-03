#include "LinkQueue.h"

int main() {
    LinkQueue<int> queue;

    // 入队操作
    queue.EnQueue(1);
    queue.EnQueue(2);
    queue.EnQueue(3);

    // 读取队头操作
    int frontValue;
    if (queue.GetHead(frontValue) == 0) {
        cout << "队头元素：" << frontValue << endl;
    }

    // 出队操作
    int dequeuedValue;
    queue.DeQueue(dequeuedValue);
    cout << "出队元素：" << dequeuedValue << endl;
    queue.DeQueue(dequeuedValue);
    cout << "出队元素：" << dequeuedValue << endl;
    queue.DeQueue(dequeuedValue);
    cout << "出队元素：" << dequeuedValue << endl;

    // 判空操作
    if (queue.Empty()) {
        cout << "队列为空" << endl;
    } else {
        cout << "队列不为空" << endl;
    }

    return 0;
}

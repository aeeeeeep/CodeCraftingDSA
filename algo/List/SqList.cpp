#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
class SqList : public List<T>{
private:
    T* data; // 存储数据的数组
    int length; // 线性表的长度
    int capacity; // 数组的容量

public:
    // 构造函数
    SqList() {
        data = new T[10]; // 默认初始容量为10
        length = 0;
        capacity = 10;
    }

    // 析构函数
    ~SqList() {
        delete[] data;
    }

    // 重载[]运算符为GetElem函数操作
    T& operator[](int i) {
        if (i < 0 || i >= length) {
            cout << "位置错误" << endl;
            throw out_of_range("位置错误");
        }
        return data[i];
    }

    // 插入操作
    void Insert(int i, const T& e) {
        if (i < 1 || i > length + 1) {
            cout << "插入位置错误" << endl;
            return;
        }
        if (length == capacity) {
            // 扩容
            T* newData = new T[2 * capacity];
            for (int j = 0; j < length; j++) {
                newData[j] = data[j];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        for (int j = length - 1; j >= i - 1; j--) {
            data[j + 1] = data[j];
        }
        data[i - 1] = e;
        length++;
    }

    // 删除操作
    void Delete(int i, T& e) {
        if (i < 1 || i > length) {
            cout << "删除位置错误" << endl;
            return;
        }
        e = data[i - 1];
        for (int j = i; j < length; j++) {
            data[j - 1] = data[j];
        }
        length--;
    }

    // 按值查找操作
    int LocateElem(const T& e) {
        for (int i = 0; i < length; i++) {
            if (data[i] == e) {
                return i + 1;
            }
        }
        return -1; // 表示未找到
    }

    // 按位查找操作
    T GetElem(int i) {
        if (i < 1 || i > length) {
            cout << "位置错误" << endl;
            throw out_of_range("位置错误");
        }
        return data[i - 1];
    }

    // 求表长
    int Length() {
        return length;
    }

    // 输出操作
    void Print() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // 判空操作
    bool Empty() {
        return length == 0;
    }
};

int main() {
    SqList<int> L;
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

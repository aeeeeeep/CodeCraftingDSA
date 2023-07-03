#include <iostream>
using namespace std;

template <typename T>
class List {
private:

public:
    // 构造函数
    List() {}

    // 析构函数
    virtual ~List() {}

    // 重载[]运算符为GetElem函数操作
    virtual T& operator[](int i) = 0;

    // 插入操作
    virtual void Insert(int i, const T& e) = 0;

    // 删除操作
    virtual void Delete(int i, T& e) = 0;

    // 按值查找操作
    virtual int LocateElem(const T& e) = 0;

    // 按位查找操作
    virtual T GetElem(int i) = 0;

    // 求表长
    virtual int Length() = 0;

    // 输出操作
    virtual void Print() = 0;

    // 判空操作
    virtual bool Empty() = 0;
};

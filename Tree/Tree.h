#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Tree {
private:

public:
    // 构造函数
    Tree() {}
    
    virtual ~Tree() {}

    // 先根遍历
    virtual vector<T> preOrder() = 0;

    // 后根遍历
    virtual vector<T> postOrder() = 0;

    // 层次遍历
    virtual vector<T> levelOrder() = 0;

    // 计算树的深度
    virtual int depth() = 0;

    // 计算节点总数
    virtual int countNodes() = 0;
};

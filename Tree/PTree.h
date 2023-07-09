#pragma once
#include "Tree.h"
using namespace std;

template <typename T>
class PTree : public Tree<T> {
private:
    struct Node {
        T data;
        int parent;  // 双亲节点的索引
    };

    vector<Node> nodes;  // 存储树的节点

public:
    // 构造函数
    PTree() {}

    // 构造函数
    PTree(const vector<T>& data, const vector<int>& parents) {
        buildTree(data, parents);
    }

    // 先根遍历
    vector<T> preOrder() {
        vector<T> result;
        preOrderTraversal(0, result);  // 从根节点开始遍历
        return result;
    }

    // 后根遍历
    vector<T> postOrder() {
        vector<T> result;
        postOrderTraversal(0, result);  // 从根节点开始遍历
        return result;
    }

    // 层次遍历
    vector<T> levelOrder() {
        vector<T> result;
        levelTraversal(result);  // 从根节点开始遍历
        return result;
    }

    // 计算树的深度
    int depth() {
        return calculateDepth(0);  // 从根节点开始计算深度
    }

    // 计算节点总数
    int countNodes() {
        return nodes.size();
    }

private:
    // 构建树
    void buildTree(const vector<T>& data, const vector<int>& parents) {
        int n = data.size();
        nodes.resize(n);

        for (int i = 0; i < n; i++) {
            nodes[i].data = data[i];
            nodes[i].parent = parents[i];
        }
    }

    // 先根遍历递归函数
    void preOrderTraversal(int nodeIndex, vector<T>& result) {
        result.push_back(nodes[nodeIndex].data);

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].parent == nodeIndex) {
                preOrderTraversal(i, result);
            }
        }
    }

    // 后根遍历递归函数
    void postOrderTraversal(int nodeIndex, vector<T>& result) {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].parent == nodeIndex) {
                postOrderTraversal(i, result);
            }
        }

        result.push_back(nodes[nodeIndex].data);
    }

    // 层次遍历递归函数
    void levelTraversal(vector<T>& result) {
        queue<int> q;
        q.push(0);  // 将根节点入队

        while (!q.empty()) {
            int nodeIndex = q.front();
            q.pop();
            result.push_back(nodes[nodeIndex].data);

            for (int i = 0; i < nodes.size(); i++) {
                if (nodes[i].parent == nodeIndex) {
                    q.push(i);
                }
            }
        }
    }

    // 计算树的深度递归函数
    int calculateDepth(int nodeIndex) {
        int maxDepth = 0;

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].parent == nodeIndex) {
                int childDepth = calculateDepth(i);
                maxDepth = max(maxDepth, childDepth);
            }
        }

        return maxDepth + 1;
    }
};

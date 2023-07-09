#pragma once
#include <unordered_map>
#include "Tree.h"
#include "BinaryTree/BinaryTree.h"

using namespace std;

template <typename T>
class CSTree : public Tree<T> {
private:
    struct CSNode {
        T data;
        CSNode* firstChild;   // 第一个子节点
        CSNode* nextSibling;  // 下一个兄弟节点

        CSNode(const T& value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
    };

    CSNode* root;  // 根节点指针

public:
    // 构造函数
    CSTree() : root(nullptr) {}

    // 构造函数
    CSTree(const vector<T>& data, const vector<int>& parents) {
        buildTree(data, parents);
    }

    // 先根遍历
    vector<T> preOrder() {
        vector<T> result;
        preOrderTraversal(root, result);  // 从根节点开始遍历
        return result;
    }

    // 后根遍历
    vector<T> postOrder() {
        vector<T> result;
        postOrderTraversal(root, result);  // 从根节点开始遍历
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
        return calculateDepth(root);  // 从根节点开始计算深度
    }

    // 计算节点总数
    int countNodes() {
        return countNodes(root);
    }

    void toBinaryTree(BinaryTree<T>& binaryTree) {
        if (root == nullptr) {
            binaryTree.setRoot(nullptr);
        }

        // 构建节点映射表
        unordered_map<CSNode*, typename BinaryTree<T>::Node*> nodeMap;
        typename BinaryTree<T>::Node* binaryRoot = buildBinaryTree(root, nodeMap);

        binaryTree.setRoot(binaryRoot);
    }

private:
    // 构建树
    void buildTree(const vector<T>& data, const vector<int>& parents) {
        int n = data.size();
        vector<CSNode*> nodes(n, nullptr);

        for (int i = 0; i < n; i++) {
            nodes[i] = new CSNode(data[i]);
        }

        for (int i = 0; i < n; i++) {
            int parentIndex = parents[i];
            if (parentIndex == -1) {
                root = nodes[i];  // 根节点
            } else {
                CSNode* parentNode = nodes[parentIndex];
                CSNode* childNode = nodes[i];
                if (parentNode->firstChild == nullptr) {
                    parentNode->firstChild = childNode;
                } else {
                    CSNode* siblingNode = parentNode->firstChild;
                    while (siblingNode->nextSibling != nullptr) {
                        siblingNode = siblingNode->nextSibling;
                    }
                    siblingNode->nextSibling = childNode;
                }
            }
        }
    }

    // 先根遍历递归函数
    void preOrderTraversal(CSNode* node, vector<T>& result) {
        if (node == nullptr) {
            return;
        }

        result.push_back(node->data);

        preOrderTraversal(node->firstChild, result);
        preOrderTraversal(node->nextSibling, result);
    }

    // 后根遍历递归函数
    void postOrderTraversal(CSNode* node, vector<T>& result) {
        if (node == nullptr) {
            return;
        }

        postOrderTraversal(node->firstChild, result);
        result.push_back(node->data);
        postOrderTraversal(node->nextSibling, result);
    }

    // 层次遍历递归函数
    void levelTraversal(vector<T>& result) {
        if (root == nullptr) {
            return;
        }

        queue<CSNode*> q;
        q.push(root);  // 将根节点入队

        while (!q.empty()) {
            CSNode* node = q.front();
            q.pop();
            result.push_back(node->data);

            CSNode* childNode = node->firstChild;
            while (childNode != nullptr) {
                q.push(childNode);
                childNode = childNode->nextSibling;
            }
        }
    }

    // 计算树的深度递归函数
    int calculateDepth(CSNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int childDepth = calculateDepth(node->firstChild);
        int siblingDepth = calculateDepth(node->nextSibling);

        return max(childDepth + 1, siblingDepth);
    }

    // 计算节点总数递归函数
    int countNodes(CSNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int childCount = countNodes(node->firstChild);
        int siblingCount = countNodes(node->nextSibling);

        return childCount + siblingCount + 1;
    }

    typename BinaryTree<T>::Node* buildBinaryTree(CSNode* csNode, unordered_map<CSNode*, typename BinaryTree<T>::Node*>& nodeMap) {
        if (csNode == nullptr) {
            return nullptr;
        }

        typename BinaryTree<T>::Node* binaryNode = new typename BinaryTree<T>::Node();
        binaryNode->data = csNode->data;
        binaryNode->left = nullptr;
        binaryNode->right = nullptr;

        // 保存节点映射关系
        nodeMap[csNode] = binaryNode;

        // 处理子节点
        if (csNode->firstChild != nullptr) {
            binaryNode->left = buildBinaryTree(csNode->firstChild, nodeMap);
        }

        // 处理兄弟节点
        if (csNode->nextSibling != nullptr) {
            binaryNode->right = buildBinaryTree(csNode->nextSibling, nodeMap);
        }

        return binaryNode;
    }
};

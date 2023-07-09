#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };

    Node* root;  // 根节点

public:
    // 构造函数
    BinaryTree() {
        root = nullptr;
    }

    // 构造函数
    BinaryTree(const string& preorder, const string& inorder, const string& postorder) {
        if (!preorder.empty() && !inorder.empty()) {
            root = buildTreeFromPreAndIn(preorder, inorder);
        } else if (!inorder.empty() && !postorder.empty()) {
            root = buildTreeFromInAndPost(inorder, postorder);
        } else {
            root = nullptr;
        }
    }

    // 析构函数
    ~BinaryTree() {
        Clear(root);
    }

    // 清空二叉树
    void Clear(Node* node) {
        if (node == nullptr) {
            return;
        }

        Clear(node->left);
        Clear(node->right);
        delete node;
    }

    // 先序遍历
    string preOrder() {
        string result;
        preOrderTraversal(root, result);
        return result;
    }

    // 中序遍历
    string inOrder() {
        string result;
        inOrderTraversal(root, result);
        return result;
    }

    // 后序遍历
    string postOrder() {
        string result;
        postOrderTraversal(root, result);
        return result;
    }

    // 层次遍历
    string levelTraverse() {
        string result;
        levelTraversal(root, result);
        return result;
    }

    // 判断是否为叶子节点
    bool isLeafNode(Node* node) {
        return (node != nullptr && node->left == nullptr && node->right == nullptr);
    }

    // 求树的深度
    int Depth() {
        return calculateDepth(root);
    }

    // 求节点总数
    int Count() {
        return countNodes(root);
    }

private:
    // 先序遍历递归函数
    void preOrderTraversal(Node* node, string& result) {
        if (node == nullptr) {
            return;
        }

        result += to_string(node->data) + " ";
        preOrderTraversal(node->left, result);
        preOrderTraversal(node->right, result);
    }

    // 中序遍历递归函数
    void inOrderTraversal(Node* node, string& result) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left, result);
        result += to_string(node->data) + " ";
        inOrderTraversal(node->right, result);
    }

    // 后序遍历递归函数
    void postOrderTraversal(Node* node, string& result) {
        if (node == nullptr) {
            return;
        }

        postOrderTraversal(node->left, result);
        postOrderTraversal(node->right, result);
        result += to_string(node->data) + " ";
    }

    // 层次遍历递归函数
    void levelTraversal(Node* node, string& result) {
        if (node == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            result += to_string(curr->data) + " ";

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }

    // 计算树的深度递归函数
    int calculateDepth(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);

        return max(leftDepth, rightDepth) + 1;
    }

    // 计算节点总数递归函数
    int countNodes(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftCount = countNodes(node->left);
        int rightCount = countNodes(node->right);

        return leftCount + rightCount + 1;
    }

    // 根据先序序列和中序序列构建二叉树
    Node* buildTreeFromPreAndIn(const string& preorder, const string& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        return buildTreeFromPreAndInHelper(preorder, 0, preorder.length() - 1, inorder, 0, inorder.length() - 1);
    }

    Node* buildTreeFromPreAndInHelper(const string& preorder, int preStart, int preEnd,
                                      const string& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        T rootValue = preorder[preStart] - '0';
        Node* root = new Node();
        root->data = rootValue;
        root->left = nullptr;
        root->right = nullptr;

        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] - '0' == rootValue) {
                inIndex = i;
                break;
            }
        }

        int leftSubtreeSize = inIndex - inStart;
        int rightSubtreeSize = inEnd - inIndex;

        root->left = buildTreeFromPreAndInHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                                 inorder, inStart, inIndex - 1);
        root->right = buildTreeFromPreAndInHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                                  inorder, inIndex + 1, inEnd);

        return root;
    }
    
    // 根据中序序列和后序序列构建二叉树
    Node* buildTreeFromInAndPost(const string& inorder, const string& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        return buildTreeFromInAndPostHelper(inorder, 0, inorder.length() - 1,
                                            postorder, 0, postorder.length() - 1);
    }

    Node* buildTreeFromInAndPostHelper(const string& inorder, int inStart, int inEnd,
                                       const string& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        T rootValue = postorder[postEnd] - '0';
        Node* root = new Node();
        root->data = rootValue;
        root->left = nullptr;
        root->right = nullptr;

        if (inStart == inEnd) {
            return root;
        }

        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] - '0' == rootValue) {
                inIndex = i;
                break;
            }
        }

        int leftSubtreeSize = inIndex - inStart;
        int rightSubtreeSize = inEnd - inIndex;

        root->left = buildTreeFromInAndPostHelper(inorder, inStart, inIndex - 1,
                                                  postorder, postStart, postStart + leftSubtreeSize - 1);
        root->right = buildTreeFromInAndPostHelper(inorder, inIndex + 1, inEnd,
                                                   postorder, postStart + leftSubtreeSize, postEnd - 1);

        return root;
    }
};

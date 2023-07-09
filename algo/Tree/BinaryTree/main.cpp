#include "BinaryTree.h"

int main() {
    // 示例1：根据先序序列和中序序列构建二叉树
    std::string preorder = "1245367";
    std::string inorder = "4251637";
    BinaryTree<int> tree1(preorder, inorder, ""); // 创建二叉树对象，后序序列为空
    std::cout << "Preorder traversal: " << tree1.preOrder() << std::endl;
    std::cout << "Inorder traversal: " << tree1.inOrder() << std::endl;
    std::cout << "Postorder traversal: " << tree1.postOrder() << std::endl;
    std::cout << "Level traversal: " << tree1.levelTraverse() << std::endl;
    std::cout << "Tree depth: " << tree1.Depth() << std::endl;
    std::cout << "Number of nodes: " << tree1.Count() << std::endl;

    // 示例2：根据中序序列和后序序列构建二叉树
    std::string inorder3 = "4251637";
    std::string postorder3 = "4526731";
    BinaryTree<int> tree3("", inorder3, postorder3); // 创建二叉树对象，先序序列为空
    std::cout << "Preorder traversal: " << tree3.preOrder() << std::endl;
    std::cout << "Inorder traversal: " << tree3.inOrder() << std::endl;
    std::cout << "Postorder traversal: " << tree3.postOrder() << std::endl;
    std::cout << "Level traversal: " << tree3.levelTraverse() << std::endl;
    std::cout << "Tree depth: " << tree3.Depth() << std::endl;
    std::cout << "Number of nodes: " << tree3.Count() << std::endl;

    return 0;
}

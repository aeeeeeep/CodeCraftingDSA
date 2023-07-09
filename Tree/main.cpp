#include "CSTree.h"

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 6};
    vector<int> parents = {-1, 0, 0, 1, 1, 2};

    CSTree<int> csTree(data, parents);

    cout << "CSTree Preorder traversal: ";
    vector<int> csPreorder = csTree.preOrder();
    for (int val : csPreorder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "CSTree Postorder traversal: ";
    vector<int> csPostorder = csTree.postOrder();
    for (int val : csPostorder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "CSTree Level order traversal: ";
    vector<int> csLevelorder = csTree.levelOrder();
    for (int val : csLevelorder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "CSTree Depth: " << csTree.depth() << endl;
    cout << "CSTree Total nodes: " << csTree.countNodes() << endl;

    BinaryTree<int> tree;
    csTree.toBinaryTree(tree);
    cout << "BTree Inorder traversal: " << tree.inOrder() << endl;
    cout << "BTree Postorder traversal: " << tree.postOrder() << endl;
    cout << "BTree Level traversal: " << tree.levelTraverse() << endl;
    cout << "BTree Tree depth: " << tree.Depth() << endl;
    cout << "BTree Number of nodes: " << tree.Count() << endl;

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

bool isIdentical(Node* root1, Node* root2) {

    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    return (root1->data == root2->data) &&
        isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right);
}

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;

    int n1, n2, val;

    cout << "Enter number of nodes in BST1: ";
    cin >> n1;

    cout << "Enter BST1 values: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        root1 = insert(root1, val);
    }

    cout << "Enter number of nodes in BST2: ";
    cin >> n2;

    cout << "Enter BST2 values: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        root2 = insert(root2, val);
    }

    cout << "\nBST1 Inorder: ";
    inorder(root1);

    cout << "\nBST2 Inorder: ";
    inorder(root2);

    if (isIdentical(root1, root2))
        cout << "\n\nBoth BSTs are identical.";
    else
        cout << "\n\nBSTs are not identical.";

    return 0;
}
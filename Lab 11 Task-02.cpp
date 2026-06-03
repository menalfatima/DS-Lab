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

Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {

    if (!root)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nBST (Inorder): ";
    inorder(root);

    int key;
    cout << "\nEnter key to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "BST after deletion: ";
    inorder(root);

    return 0;
}
#include <iostream>
using namespace std;

struct BSTNode {
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int i, string t) {
        isbn = i;
        title = t;
        left = right = NULL;
    }
};

struct ListNode {
    int isbn;
    string title;
    ListNode* next;

    ListNode(int i, string t) {
        isbn = i;
        title = t;
        next = NULL;
    }
};

BSTNode* insert(BSTNode* root, int isbn, string title) {

    if (!root)
        return new BSTNode(isbn, title);

    if (isbn < root->isbn)
        root->left = insert(root->left, isbn, title);

    else if (isbn > root->isbn)
        root->right = insert(root->right, isbn, title);

    return root;
}

void bstToList(BSTNode* root, ListNode*& head, ListNode*& tail) {

    if (!root)
        return;

    bstToList(root->left, head, tail);

    ListNode* newNode = new ListNode(root->isbn, root->title);

    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    bstToList(root->right, head, tail);
}

void printList(ListNode* head) {

    while (head) {
        cout << "ISBN: " << head->isbn
            << " | Title: " << head->title << endl;

        head = head->next;
    }
}

int main() {

    BSTNode* root = NULL;

    int n, isbn;
    string title;

    cout << "Enter number of books: ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {

        cout << "\nEnter ISBN: ";
        cin >> isbn;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        root = insert(root, isbn, title);
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    bstToList(root, head, tail);

    cout << "\nSorted Library Catalog:\n";
    printList(head);

    return 0;
}
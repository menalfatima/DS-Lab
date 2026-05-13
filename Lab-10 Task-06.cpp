#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void printForward(Node* head)
{
    if (head == NULL) return;

    cout << head->data << " ";
    printForward(head->next);
}

void printReverse(Node* head)
{
    if (head == NULL) return;

    printReverse(head->next);
    cout << head->data << " ";
}

Node* insertBegin(Node* head, int val)
{
    Node* newNode = new Node{ val, head, NULL };

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

Node* insertEnd(Node* head, int val)
{
    if (head == NULL)
        return new Node{ val, NULL, NULL };

    head->next = insertEnd(head->next, val);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

Node* insertPos(Node* head, int val, int pos)
{
    if (pos == 1)
        return insertBegin(head, val);

    if (head == NULL)
        return NULL;

    head->next = insertPos(head->next, val, pos - 1);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

Node* deleteValue(Node* head, int val)
{
    if (head == NULL) return NULL;

    if (head->data == val)
    {
        Node* temp = head->next;

        if (temp != NULL)
            temp->prev = NULL;

        delete head;
        return temp;
    }

    head->next = deleteValue(head->next, val);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

Node* deletePos(Node* head, int pos)
{
    if (head == NULL) return NULL;

    if (pos == 1)
    {
        Node* temp = head->next;

        if (temp != NULL)
            temp->prev = NULL;

        delete head;
        return temp;
    }

    head->next = deletePos(head->next, pos - 1);

    if (head->next != NULL)
        head->next->prev = head;

    return head;
}

int search(Node* head, int val, int idx = 1)
{
    if (head == NULL) return -1;

    if (head->data == val)
        return idx;

    return search(head->next, val, idx + 1);
}

Node* getTail(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    return getTail(head->next);
}

bool isPalHelper(Node* left, Node* right)
{
    if (left == NULL || right == NULL)
        return true;

    if (left == right)
        return true;

    if (left->data != right->data)
        return false;

    if (left->next == right || right->prev == left)
        return true;

    return isPalHelper(left->next, right->prev);
}

bool isPalindrome(Node* head)
{
    if (head == NULL)
        return true;

    Node* tail = getTail(head);

    return isPalHelper(head, tail);
}

int main()
{
    Node* head = NULL;

    head = insertBegin(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);

    cout << "Forward: ";
    printForward(head);
    cout << endl;

    cout << "Reverse: ";
    printReverse(head);
    cout << endl;

    cout << "Search 3 at position: " << search(head, 3) << endl;

    if (isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    head = deleteValue(head, 3);

    cout << "After deletion: ";
    printForward(head);
    cout << endl;

    return 0;
}
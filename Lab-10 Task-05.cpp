#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    printList(head->next);
}

Node* insertBegin(Node* head, int value)
{
    Node* newNode = new Node{ value, head };
    return newNode;
}

Node* insertEnd(Node* head, int value)
{
    if (head == NULL)
    {
        return new Node{ value, NULL };
    }

    head->next = insertEnd(head->next, value);
    return head;
}

Node* insertPos(Node* head, int value, int pos)
{
    if (pos == 1)
    {
        return new Node{ value, head };
    }

    if (head == NULL)
    {
        cout << "Invalid Position\n";
        return NULL;
    }

    head->next = insertPos(head->next, value, pos - 1);
    return head;
}

Node* deleteValue(Node* head, int value)
{
    if (head == NULL)
        return NULL;

    if (head->data == value)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deleteValue(head->next, value);
    return head;
}

Node* deletePos(Node* head, int pos)
{
    if (head == NULL)
        return NULL;

    if (pos == 1)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    head->next = deletePos(head->next, pos - 1);
    return head;
}

int search(Node* head, int value, int index = 1)
{
    if (head == NULL)
        return -1;

    if (head->data == value)
        return index;

    return search(head->next, value, index + 1);
}

int main()
{
    Node* head = NULL;

    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);

    cout << "After insert at beginning: ";
    printList(head);
    cout << endl;

    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    cout << "After insert at end: ";
    printList(head);
    cout << endl;

    head = insertPos(head, 25, 3);

    cout << "After insert at position 3: ";
    printList(head);
    cout << endl;

    head = deleteValue(head, 20);

    cout << "After deleting value 20: ";
    printList(head);
    cout << endl;

    head = deletePos(head, 2);

    cout << "After deleting position 2: ";
    printList(head);
    cout << endl;

    int pos = search(head, 40);
    cout << "Search 40 found at position: " << pos << endl;

    return 0;
}
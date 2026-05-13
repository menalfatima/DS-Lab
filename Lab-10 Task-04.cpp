#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* head)
{
    if (head == NULL)
    {
        return;
    }

    cout << head->data << " ";

    printList(head->next);
}

int main()
{

    Node* head = new Node{ 10, nullptr };
    head->next = new Node{ 20, nullptr };
    head->next->next = new Node{ 30, nullptr };
    head->next->next->next = new Node{ 40, nullptr };

    cout << "Linked List: ";
    printList(head);

    return 0;
}
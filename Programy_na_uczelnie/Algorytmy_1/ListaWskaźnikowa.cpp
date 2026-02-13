#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push_front(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void push_back(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next)
        current = current->next;

    current->next = newNode;
}

void pop_front(Node*& head)
{
    if (!head) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void print_list(Node* head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout<<"nullptr"<<endl;
}

void clear_list(Node*& head)
{
    while (head)
        pop_front(head);
}

int main()
{
    Node* head = nullptr;

    push_front(head, 3);
    push_front(head, 1);
    push_back(head, 5);

    print_list(head);

    clear_list(head);
    return 0;
}

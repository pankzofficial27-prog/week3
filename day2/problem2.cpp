#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node* removeNth(Node* head, int n)
{
    Node dummy(0);
    dummy.next = head;

    Node* fast = &dummy;
    Node* slow = &dummy;

    for(int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node* del = slow->next;
    slow->next = slow->next->next;
    delete del;

    return dummy.next;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = removeNth(head, 2);

    printList(head);

    return 0;
}
#include <iostream>
#include <vector>
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

bool isPalindrome(Node* head)
{
    vector<int> v;

    while(head != NULL)
    {
        v.push_back(head->data);
        head = head->next;
    }

    int i = 0;
    int j = v.size() - 1;

    while(i < j)
    {
        if(v[i] != v[j])
            return false;

        i++;
        j--;
    }

    return true;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if(isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
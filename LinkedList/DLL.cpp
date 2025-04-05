#include <iostream>
#include <vector>

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution
{
public:
    Node *constructDLL(std::vector<int> &arr)
    {
        Node *head, *tail = nullptr;

        for (int i = 0; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            if (i == 0)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
        }

        return head;
    }
};
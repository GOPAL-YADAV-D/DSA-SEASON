#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *to)
    {
        this->data = data;
        this->next = to;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int numberOfElements;

    LinkedList() : head(nullptr), tail(nullptr), numberOfElements(0) {};

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    void add_element_start(int value)
    {
        Node *newNode = new Node(value);
        if (this->head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        numberOfElements++;
    }

    void add_elements_end(int value)
    {
        Node *newNode = new Node(value);
        if (this->tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        numberOfElements++;
    }

    void add_element_middle(int value, int afterValue)
    {
        Node *iterator = this->head;

        while (iterator->next != nullptr && iterator->data != afterValue)
        {
            iterator = iterator->next;
        }

        if (iterator == nullptr)
        {
            std::cout << "Value " << afterValue << " not found.\n";
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = iterator->next;
        iterator->next = newNode;

        if (iterator == tail)
        {
            tail = newNode;
        }

        numberOfElements++;
    }

    void delete_node(int deleteValue)
    {
        if (this->head == nullptr)
            return;

        Node *iterator = this->head;

        if (head->data == deleteValue)
        {
            head = head->next;
            delete iterator;

            if (head == nullptr)
                tail = nullptr;

            numberOfElements--;
            return;
        }
        // Search for the element that needs to be deleted

        Node *previous = nullptr;

        // while (iterator->next != nullptr)
        // {
        //     if (iterator->data != deleteValue)
        //     {
        //         previous = iterator;
        //         iterator = iterator->next;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }

        while (iterator != nullptr && iterator->data != deleteValue)
        {
            previous = iterator;
            iterator = iterator->next;
        }
        if (iterator == nullptr)
        {
            std::cout << "Value " << deleteValue << " not found.\n";
            return;
        }

        previous->next = iterator->next;
        if (iterator == tail)
        {
            tail = previous;
        }
        delete iterator;

        numberOfElements--;
    }

    int length()
    {
        int count = 0;
        Node *iterator = head;

        while (iterator != nullptr)
        {
            count++;
            iterator = iterator->next;
        }

        return count;
    }

    bool searchKey(int key)
    {
        Node *iterator = head;
        while (iterator != nullptr)
        {
            if (iterator->data == key)
                return true;
            iterator = iterator->next;
        }
        return false;
    }
};
#include <iostream>

/*
    Created by: Weston McNamara in 2021

    This class is a basic implementation of the linked list data structure.

    It dynamically allocates memory and properly disposes of it without issue.

    Functions:
    AddNode() //adds node to the end of the linked list
    RemoveNode() //removes a node from anywhere in the list
    Print() //logs the linked list data to std::cout
*/

class Node
{
public:
    int data = 0;
    Node* next = nullptr;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }

    friend class LinkedList;
};

class LinkedList
{
public:
    LinkedList() = default;
    ~LinkedList()
    {
        Node* tmp = head;
        while (tmp->next != nullptr)
        {
            Node* delTmp = tmp;
            tmp = tmp->next;

            delete delTmp;
        }

        delete tmp;
    }

    Node* AddNode(int data)
    {
        //Default add node.
        if (head == nullptr)
        {
            head = new Node(data);
            return nullptr;
        }

        Node* tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }

        tmp->next = new Node(data);
        return tmp->next;
    }

    void RemoveNode(Node* node)
    {
        if (head == nullptr)
            return;

        Node* tmp = head;

        while (tmp->next != node)
        {
            tmp = tmp->next;
        }

        tmp->next = node->next;
        delete node;
    }

    void Print()
    {
        Node* tmp = head;

        while (tmp->next != nullptr)
        {
            std::cout << tmp->data << "\n";
            tmp = tmp->next;
        }

        std::cout << tmp->data << "\n";
    }

private:
    Node* head = nullptr;
};

int main()
{
    LinkedList list;
    list.AddNode(10);
    list.AddNode(20);
    Node* node = list.AddNode(30);
    list.AddNode(40);

    list.Print();

    list.RemoveNode(node);
    list.Print();
}
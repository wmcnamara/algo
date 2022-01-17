/*
    C++ binary search tree implementation, created by Weston McNamara.

    It features Inserting, and Searching, and uses a recursive approach for each problem.
*/

#include <iostream>

struct Node
{
    Node* parent = nullptr;

    Node* left = nullptr;
    Node* right = nullptr;

    int value = 0;
};

void Insert(Node* next, Node* val)
{
    if (next == nullptr)
        return;

    if (next->value == val->value)
        return;

    if (val->value < next->value)
    {
        //Insert at the left
        if (next->left == nullptr)
        {
            next->left = val;
            val->parent = next; //set the parent
        }
        else //recurse through left node
        {
            Insert(next->left, val);
        }
    }

    if (val->value > next->value)
    {
        //Insert at the left
        if (next->right == nullptr)
        {
            next->right = val;
            val->parent = next; //set the parent
        }
        else //recurse through left node
        {
            Insert(next->right, val);
        }
    }
}

bool Lookup(Node* next, int val)
{
    if (next == nullptr)
        return false;

    if (next->value == val)
        return true;

    if (val > next->value && next->right != nullptr)
    {
        return Lookup(next->right, val);
    }
    else if (val < next->value && next->left != nullptr)
    {
        return Lookup(next->left, val);
    }
    else
    {
        return false;
    }
}

int main() {
    Node head;
    head.value = 1;

    Node r;
    r.value = 3;

    Node l;
    l.value = -1;

    head.left = &l;
    head.right = &r;

    std::cout << Lookup(&head, -1);
}
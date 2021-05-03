#include <iostream>

/*
    Created by: Weston McNamara in 2021

    This class is a basic implementation of the stack data structure.

    It dynamically allocates memory and properly disposes of it without issue.

    Functions:
    Push() //pushes element to the end of the stack
    RemoveNode() //pushes element off the top of the stack
*/

class Stack
{
public:
    Stack(int size)
    {
        maxCount = size;
        dataptr = new int[size];
    }

    ~Stack()
    {
        delete[] dataptr;
    }

    void Push(int data)
    {
        if (currentCount + 1 > maxCount)
            return;

        currentCount++;
        dataptr[currentCount] = data;
    }

    int Pop()
    {
        if (currentCount - 1 < 0)
            return 0;

        return dataptr[currentCount--];
    }

private:
    int currentCount = 0;
    int maxCount = 0;
    int* dataptr = nullptr;
};

int main()
{
    //testing 

    Stack stack(3);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    std::cout << stack.Pop() << "\n";
    std::cout << stack.Pop() << "\n";
    std::cout << stack.Pop() << "\n";
}
#include <memory>
#include <iostream>

struct Node 
{
public:
	Node(int data, std::unique_ptr<Node> ptr) : mData(data), next(std::move(ptr)) {}
	int mData = 0;
	std::unique_ptr<Node> next = nullptr;
};

class LinkedList 
{	
public:
	LinkedList(int data) : head(std::make_unique<Node>(data, nullptr)) {}

	inline void Add(int data) 
	{
		Node* current = head.get();

		while (current->next != nullptr) 
		{
			current = current->next.get();
		}
				
		current->next = std::make_unique<Node>(data, nullptr);
	}

	inline void Print() 
	{
		Node* current = head.get();

		while (current->next != nullptr)
		{
			std::cout << current->mData << "\n";
			current = current->next.get();
		}

		std::cout << current->mData << "\n";
	}

private:
	std::unique_ptr<Node> head = nullptr;
};
#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO:
		while (first_)
		{
			PopFront();
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr; // TODO:
	}

	int Size()
	{
		int size = 0;

		// TODO:
		Node* temp = first_;
		while (temp)
		{
			size++;
			temp = temp->right;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:
			while (current->right)
			{
				cout << current->item << " ";
				current = current->right;
			}
			cout << current->item << endl;
			
			cout << "Backward: ";
			while (current->left)
			{
				cout << current->item << " ";
				current = current->left;
			}
			cout << current->item << endl;
		}
	}

	Node* Find(T item)
	{
		Node* temp = first_;
		while (temp)
		{
			if (temp->item == item)
			{
				return temp;
			}

			temp = temp->right;
		}

		return nullptr; // TODO:
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO: while이 필요없음

			Node* temp = new Node;
			temp->item = item;

			temp->right = node->right;
			node->right = temp;

			if (temp->right)
			{
				temp->right->left = temp;
			}

			temp->left = node;
		}
	}

	void PushFront(T item)
	{
		// TODO:
		Node* temp = new Node;
		temp->item = item;
		temp->right = first_;
		temp->left = nullptr;
		
		if(first_)first_->left = temp;
		first_ = temp;
	}

	void PushBack(T item)
	{
		// TODO:
		Node* newNode = new Node;
		newNode->item = item;
		newNode->right = nullptr;
		newNode->left = nullptr;

		if (!first_)
		{
			first_ = newNode;
			return;
		}

		Node* temp = first_;

		while (temp->right)
		{
			temp = temp->right;
		}

		temp->right = newNode;
		newNode->left = temp;
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO:
		Node* temp = first_->right;
		
		delete first_;

		if (temp)
		{
			first_ = temp;
			temp->left = nullptr;
		}
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		// TODO:
		Node* temp = first_;

		while (temp->right)
		{
			temp = temp->right;
		}

		if (temp->left) temp->left->right = nullptr;
		else first_ = nullptr;
		delete temp;
	}

	void Reverse()
	{
		// TODO:
		//if (!first_) return;

		//Node* current = first_;
		//Node* next = nullptr;

		//while (current)
		//{
		//	Node* next = current->right;
		//	current->right = current->left;
		//	current->left = next; 


		//	//1 2 3 4 5
		//	//        5 4 3 2 1
		//	if (!next) first_ = current;
		//	current = next;
		//}

		if (IsEmpty()) return;
		else
		{
			Node* current = first_;
			Node* prev = nullptr;

			while (current)
			{
				prev = current;
				current = current->right;
				std::swap(prev->left, prev->right); // 두 변수가 들고 있는 주소 값이 바뀜.
			}

			first_ = prev;
		}
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO:
	}

	T Back()
	{
		assert(first_);

		Node* temp = first_;
		while (temp->right)
		{
			temp = temp->right;
		}

		return temp->item; // TODO:
	}

protected:
	Node* first_ = nullptr;
};
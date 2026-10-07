#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: 연결 리스트 복사

		Node* temp = list.first_;
		while (temp)
		{
			PushBack(temp->item);
			temp = temp->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
		Node* temp = first_;
		while (temp)
		{
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size를 하나하나 세어서 반환

		Node* temp = first_;
		return 1;

		while (temp)
		{
			size++;
			temp = temp->next;
		}

		return size;
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO: 수정
	}

	T Back()
	{
		assert(first_);

		Node* temp = first_;
		
		while (temp->next)
		{
			temp = temp->next;
		}

		return temp->item; // TODO:
	}

	Node* Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환

		Node* temp = first_;
		while (temp)
		{
			if (temp->item == item) return temp;
			temp = temp->next;
		}
		return nullptr;
	}

	void InsertBack(Node* node, T item)
	{
		// TODO:
		Node* temp = new Node;
		temp->item = item;
		temp->next = node->next;
		node->next = temp;
	}

	void Remove(Node* n)
	{
		assert(first_);
		
		//TODO
		if (first_ == n)
		{
			first_ = first_->next;
			delete n;
			return;
		}

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO: 
		Node* temp = first_;

		while (temp->next)
		{
			if (temp->next == n)
			{
				temp->next = temp->next->next;
				delete n;
			}
			temp = temp->next;
		}
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		// TODO:
		Node* temp = new Node;
		temp->item = item;
		
		// 연결 관계 정리
		// TODO:
		temp->next = first_; //first_는 nullptr 또는 주소가 들어있을테지
		first_ = temp;
	}

	void PushBack(T item)
	{
		Node* itemNode = new Node;
		itemNode->item = item;
		itemNode->next = nullptr;

		if (first_)
		{
			// TODO:
			Node* temp = first_;

			while (temp->next)
			{
				temp = temp->next;
			}

			temp->next = itemNode;
		}
		else //첫 요소일 경우
		{
			// TODO:
			first_ = itemNode;
		}
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

		// TODO: 메모리 삭제
		Node* temp = first_;
		first_ = first_->next;
		
		delete temp;
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

		// TODO: 메모리 삭제

		Node* temp = first_;
		Node* prev = nullptr;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		
		if (prev)
		{
			prev->next = nullptr;
		}
		else
		{
			first_ = nullptr;
		}

		delete temp;
	}

	void Reverse()
	{
		// TODO: 
		// 처음 것이 nullptr을 가리키고 마지막 것이 first_가 가리킴 받아야 함.
		
		Node* prev = nullptr;
		Node* current = first_;

		while (current) //임시저장, 이전 주소 쪽으로 next 연결, prev, current 옮기기
		{
			Node* next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		first_ = prev;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}
				
				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node* first_ = nullptr;

	bool print_debug_ = false;
};
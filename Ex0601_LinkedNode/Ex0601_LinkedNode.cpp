#include <iostream>

using namespace std;

struct Node
{
	int item = 0;	  // <- 큰 데이터도 가능
	Node* next = nullptr;

	friend ostream& operator<<(ostream& os, const Node& n)
	{
		cout << "[" << &n << ", " << n.item << ", " << n.next<< "]" << flush;
		return  os;
	}
};

void RecurPrint(Node* node)
{
	// TODO: 재귀

	if (node->next == nullptr) return;
	cout << *node << endl;
	RecurPrint(node->next);
}

void IterPrint(Node* node)
{
	// TODO:
	Node* temp = node;

	while (temp->next != nullptr) //next가 nullptr 까지
	{
		cout << *temp << endl;
		temp = temp->next;
	}
}

int main()
{
	// ListArray와 비교

	Node* first = nullptr;
	first = new Node;
	first->item = 1;
	first->next = nullptr;

	Node* second = nullptr;
	second = new Node;
	second->item = 2;
	second->next = nullptr;

	Node* third = nullptr;
	third = new Node;
	third->item = 3;
	third->next = nullptr;

	Node* fourth = nullptr;
	fourth = new Node;
	fourth->item = 4;
	fourth->next = nullptr;

	Node* fifth = nullptr;
	fifth = new Node;
	fifth->item = 5;
	fifth->next = nullptr;

	// 계속 추가 가능

	cout << *first << endl;
	cout << *second << endl;
	cout << *third << endl;
	cout << *fourth << endl;
	cout << *fifth << endl;
	cout << endl;

	// 연결 관계 만들어 주기
	// first->next = second;
	// TODO:
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;

	// 마지막

	cout << *(first) << endl;
	cout << *(first->next) << endl;
	cout << *(first->next->next) << endl;
	cout << *(first->next->next->next) << endl;
	cout << *(first->next->next->next->next) << endl;
	// cout << *(first->next->next->next->next->next) << endl; // 오류

	cout << endl;

	// 재귀 호출 이용
	RecurPrint(first);
	cout << endl;

	// 반복문 이용
	IterPrint(first);
	cout << endl;

	// TODO: 데이터 삭제
	Node* current = first;

	while (current)
	{
		Node* temp = current;
		
		cout << "delete: " << *temp << endl;

		current = current->next;
		
		delete temp;
	}

	return 0;
}

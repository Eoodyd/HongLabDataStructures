#pragma once

#include "Queue.h"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (덱, dequeue와 구분)
template<typename T>
class Deque : public Queue<T>
{

	typedef Queue<T> Base;

public:
	Deque(int capacity)
		: Queue<T>(capacity)
	{
	}

	T& Front()
	{
		return Base::Front();
	}

	T& Back()
	{
		return Base::Rear();
	}

	void PushFront(const T& item)
	{
		if (Base::IsFull())
			Base::Resize();

		// TODO:
		Base::queue_[Base::front_] = item;
		Base::front_ = (Base::front_ == 0) ? Base::capacity_ - 1: Base::front_ - 1;
		//Base::front_ = (Base::front_ - 1 + Base::capacity_) % Base::capacity_;
	}

	void PushBack(const T& item)
	{
		Base::Enqueue(item);
	}

	void PopFront()
	{
		Base::Dequeue();
	}

	void PopBack()
	{
		assert(!Base::IsEmpty());

		// TODO:
		
		Base::queue_[Base::rear_] = 0;
		Base::rear_ = (Base::rear_ == 0) ? Base::capacity_ - 1 : Base::rear_ - 1;
	}

private:
	// Queue와 동일
	//int& rear_ = Base::rear_; // 이런 방식으로 변수를 연결해 Base::를 제거하는 방법도 잇음.
};

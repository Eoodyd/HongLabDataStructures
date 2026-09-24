#include "MyString.h"

using namespace std;

// 비어 있는 MyString() 생성
MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
MyString::MyString(const char* init)
{
	size_ = 0;
	while (init[size_] != '\0') // \0이 나타나기 전까지 사이즈 카운터해서 측정
	{
		size_++; //char는 1바이트라서 sizeof를 곱할 필요가 없다. 
	}

	str_ = new char[size_]; // 메모리에 사이즈만큼 할당

	memcpy(str_, init, size_); //복사. 목적지, 소스, 복사할 크기
}

// MyString의 다른 instance로부터 초기화
MyString::MyString(const MyString& str)
{
	//원본 객체를 인수로 받음.(const라 원본 수정 불가)

	size_ = str.size_;
	str_ = new char[size_];
	memcpy(str_, str.str_, size_); //주소가 가리키는 곳의 내용을 그대로 str_에 복사
}

MyString::~MyString() //소멸자
{
	// 생성자에서 new로 빌린 힙 메모리를 돌려주는 일.
	if (str_ != nullptr) 
	{
		delete[] str_;
		str_ = nullptr;
		size_ = 0;
	}
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // 편의상 참조& 사용
{
	// 힌트: str.str_, str.size_ 가능
	if (size_ != str.size_)
	{
		return false;
	}
	
	for (int i = 0; i < size_; i++)
	{
		if (str_[i] != str.str_[i])
		{
			return false;
		}
	}

	return true;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	if (new_size == size_) return;

	char* temp = new char[new_size]; //메모리 생성
	for (int i = 0; i < (new_size < size_ ? new_size : size_); i++)
	{
		temp[i] = str_[i];
	}

	delete[] str_; //소멸자는 객체가 사라질 때 부르는 것.
	str_ = temp; // 메모리 연결
	size_ = new_size; 
}

// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
MyString MyString::Substr(int start, int num) //앞의 MyString은 반환타입, MyString::은 함수의 클래스 소속
{
	// 복사할 인덱스: start, start + 1, ... , start + num - 1
	assert(start + num - 1 < this->size_); // 문제를 단순하게 만들기 위해 가정

	MyString temp;
	temp.str_ = new char[num];
	temp.size_ = num;

	for (int i = start; i < start + num; i++)
	{
		temp.str_[i - start] = str_[i];
	}

	return temp;
}

MyString MyString::Concat(MyString app_str) //문자열 뒤에 app_str을 이어붙인다.
{
	MyString temp;

	temp.Resize(size_ + app_str.size_);
	memcpy(temp.str_, str_, size_);
	memcpy(&temp.str_[size_], app_str.str_, app_str.size_); //&는 주소연산자

	return temp;
}

MyString MyString::Insert(MyString t, int start) //start 자리에 t를 삽입해서 반환
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;
	temp.Resize(size_ + t.size_);
	
	
	memcpy(temp.str_, str_, start); // 여기서 start는 크기로 생각하기
	memcpy(&temp.str_[start], t.str_, t.size_); 
	memcpy(&temp.str_[start + t.size_], &str_[start], size_ - start); 

	return temp;
}

int MyString::Find(MyString pat)
{
	//TODO:
	//adcdef 에서 def를 찾을 때, 6-3+1
	int check = 0;

	//일단 pat.str_[0]이 포함된 부분을 긁어모으기
	for (int j = 0; j < Length() - pat.Length()+1; j++)
	{
		int count = 0;
		for (int i = 0; i < pat.Length() && pat.str_[i] == str_[j + i]; i++)
		{
			count++;
			if (count == pat.Length()) return j;
		}
	}

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}
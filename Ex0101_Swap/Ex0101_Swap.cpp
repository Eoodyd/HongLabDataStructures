#include <iostream>

using namespace std;

void MySwapPtr(int* i, int* j) //int*: 포인터 변수를 의미
{
	int temp = *i; //*i: i의 주소가 가리키는 값
	*i = *j;
	*j = temp;
}

void MySwapRef(int& i, int& j) //int&: 주소가 가리키는 곳의 값
{
	int temp = i;
	i = j; //그 변수 그 자체를 가져옴
	j = temp;

}

bool CheckSorted(int a, int b)
{
	return false;
}

int main()
{
	// Swap
	{
		int a = 3;
		int b = 2;
		
		cout << a << " " << b << endl;

		// TODO:
		MySwapRef(a,b);
		//MySwapPtr(&a ,&b ); //&a: a의 주소를 가져옴
		cout << a << " " << b << endl;
	}


	// 정렬(sorting)
	{
		int arr[] = { 9, 3 };

		cout << arr[0] << " " << arr[1] << endl;
		
		// TODO:

		cout << arr[0] << " " << arr[1] << endl;
	}

	// 값과 상관 없이 항상 작은 값이 먼저 출력되게 하려면?
	// 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력되지 않게 하려면?
	{
		int arr[2];

		// TODO:
	}

	return 0;
}

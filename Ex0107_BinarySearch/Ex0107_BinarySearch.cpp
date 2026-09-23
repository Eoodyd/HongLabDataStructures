#include <iostream>
#include <iomanip>      // std::setw

#include <cassert>

using namespace std;

void PrintHelper(int* arr, int n, int left, int right)
{
	cout << "[" << left << "," << right << "]" << endl;

	cout << "Indices: ";
	for (int i = left; i <= right; i++)
		cout << setw(2) << i << " ";
	cout << endl;

	cout << "Values : " << setw(2);
	for (int i = left; i <= right; i++)
		cout << setw(2) << arr[i] << " ";
	cout << endl;
}

int BinarySearch(int* arr, int n, int x) // 이진 탐색
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		//PrintHelper(arr, n, left, right);

		//TODO:
		int middle = (left + right) / 2;

		if (x < arr[middle])
		{
			right = middle - 1;
		}
		else if(x > arr[middle])
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return -999;

	// 시간 복잡도
	// n개의 배열을 절반으로 나누는 것을 반복하여 요소가 1개가 남을때까지 진행하는 비교 횟수
	// n/2^x = 1  
	// x = log2(n) 
	// 대략적으로 log2(n) 회가 걸린다. 여기서 확인과정 1회 따로 포함하면, log2(n) + 1 
	// O(log2(n))
}


int main()
{
	// 정렬된 배열 (임의의 배열 사용 가능, 여기서는 디버깅 편의를 위해 index와 같은 값)
	//int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr[] = { 2, 4, 5, 5, 6, 8, 9, 10, 12, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);

	assert(n > 0);

	// 정렬이 안된 배열은 미리 정렬
	for (int x = 0; x < n; x++)
		cout << x << "가 위치한 인덱스: " << BinarySearch(arr, n, x) << endl;
}

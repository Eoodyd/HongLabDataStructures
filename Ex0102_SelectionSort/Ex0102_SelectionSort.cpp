#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

struct Element
{
	int key;
	char value;
};

bool CheckSorted(int* arr, int size)
{
	// TODO: 정렬 확인 함수 구현
	for (int a = 0; a < size-1; a++)
	{
		if (a > a + 1)
		{
			return false;
		}
	}
	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Print(Element* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i].key << " ";
	cout << endl;

	for (int i = 0; i < size; i++)
		cout << arr[i].value << " ";
	cout << endl;
}

int main()
{
	// 3개 정렬
	{
		for (int k = 0; k < 3; k++)
			for (int j = 0; j < 3; j++)
				for (int i = 0; i < 3; i++) {

					int arr[3] = { i, j, k };
					int size = sizeof(arr) / sizeof(arr[0]);

					for (int e = 0; e < size; e++) {
						//cout << arr[e] << " " << flush;
					}

					//cout << " -> " << flush;

					// 부등오 < 과 <= 헷갈리지 말기
					for (int b = 0; b < size-1; b++)
					{
						for (int a = b + 1; a < size; a++)
						{
							if (arr[b] > arr[a])
							{
								swap(arr[b], arr[a]);
							}
						}
					}

					// 트럼프 카드 5개를 나열했을 때, 가장 작은 임시 값과 모든 요소 크기를 비교한 후에 정렬하는 방식도 있을 것

					for (int e = 0; e < size; e++) {
						cout << arr[e] << " " << flush;
					}

					cout << boolalpha;
					cout << CheckSorted(arr, size); // 정렬 되었나 확인
					cout << endl;
				}
	}
		
	// Selection Sort: (오름차순 예시)가장 작은 요소를 찾아 지정 위치와 스왑하는 것을 반복하여 정렬
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		int min_index; // for문 내에서 정의한다면 계속 새로 생성해야함.
		for (int i = 0; i < size - 1; i++)
		{
			// TODO:
			min_index = i;
			for (size_t j = i + 1; j < size; j++)
			{
				if (arr[min_index] > arr[j])
				{
					min_index = j;
				}
			}

			swap(arr[i], arr[min_index]);

			Print(arr, size);

			cout << boolalpha;
			cout << CheckSorted(arr, size);
			cout << endl;
		}
	}

	// 비교 횟수 세보기, 더 효율적인 방법은 없을까?
	// https://en.wikipedia.org/wiki/Sorting_algorithm
	{
		ofstream ofile("logEoodyd.txt");
		for (int size = 1; size < 1000; size++)
		{
			int count = 0;
			int* arr = new int[size];
			for (int s = 0; s < size; s++) 
			{
				arr[s] = size - s;
			}

			//TODO: count ++;
			int min_index; 
			for (size_t i = 0; i < size-1; i++)
			{
				min_index = i;
				for (size_t j = i+1; j < size; j++)
				{
					count++;

					if (arr[j] < arr[min_index])
					{
						min_index = j;
					}
				}
				swap(arr[i], arr[min_index]);
			}

			//cout << size << ", " << count << endl;
			ofile << size << ", " << count << endl;
			// Print(arr, size);

			delete[] arr;
		}

		ofile.close();
	}

	// [2, 2, 1]
	// [1, 2, 2] // 첫 2가 마지막으로 이동

	// 안정성 확인(unstable): 같은 key 값끼리 정렬을 하지않고 위치가 기존 그대로 유지되면 stable 한 것.
	{
		Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
		int size = sizeof(arr) / sizeof(arr[0]);

		Print(arr, size); // arr이 Element의 배열

		// TODO:

		Print(arr, size); // arr이 Element의 배열
	}
}

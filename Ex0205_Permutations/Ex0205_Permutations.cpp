#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

void RecurPermutations(char* arr, int left, int right)
{
	// arr[left], ..., arr[right]

	if (left == right)
	{
		for (int i = 0; i <= right; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		// 힌트
		// - for, swap(), 재귀호출
		// - 같은 변수끼리도 swap() 가능
		// - right는 고정

		// TODO: 4321
		// abc를 기준으로 마인드맵으로 가장 먼저 나오는 것들 순서 추려서 다시 배열 원상복구 시키는 법 보기.
		for (int i = left; i <= right; i++)
		{
			swap(arr[left], arr[i]);
			RecurPermutations(arr, left + 1, right); // i+1이 아님. 앞에꺼 픽스하고 옮겨서 진행
			swap(arr[left], arr[i]);

		}
	}
}

int main()
{
	/* a 한 글자의 순열 (Permutations)

		a
	*/

	/* ab 두 글자의 순열 (Permutations)

		a b
		b a
	*/

	/*  abc 3 글자의 순열 (Permutations)

		a b c
		a c b
		b a c
		b c a
		c b a
		c a b
	*/

	// Permutations
	char arr[] = "abcd";
	
	/*cout << "RecurPermutations(arr, 0, 0): " << endl;
	RecurPermutations(arr, 0, 0);
	cout << endl;

	cout << "RecurPermutations(arr, 0, 1): " << endl;
	RecurPermutations(arr, 0, 1);
	cout << endl;*/

	cout << "RecurPermutations(arr, 0, 2): " << endl;
	RecurPermutations(arr, 0, 2);
	cout << endl;

	cout << "RecurPermutations(arr, 0, 3): " << endl;
	RecurPermutations(arr, 0, 3);
	cout << endl;

	return 0;
}

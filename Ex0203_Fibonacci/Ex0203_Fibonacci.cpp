#include <iostream>
#include <cassert>
#include <algorithm> // swap
#include <iomanip> // setw

using namespace std;

//int Fibonacci(int n) //재귀호출을 사용하지 않고 구현
//{
//	if (n == 0)
//		return 0; // F0 = 0 
//	else if (n == 1)
//		return 1; // F1 = 1
//	else
//	{
//		int a = 0, b = 1;
//		int count = 0;
//		// TODO:
//		while (++count <= n/2)
//		{
//			a = a + b; // 짝수  n=4이면 2회 돌리고 a를 받아야함.
//			b = b + a; // 홀수	n=5이면 2회 돌리고 b를 받아야함.
//		}
//
//		if (n % 2 == 0) return a;
//		return b;
//	}
//}

int Fibonacci(int n) //재귀호출을 사용하지 않고 구현(강사님 풀이식)
{
	if (n == 0)
		return 0; // F0 = 0 
	else if (n == 1)
		return 1; // F1 = 1
	else
	{
		int prev1 = 0;
		int prev2 = 1;
		int fn = 0;
		for (int i = 2; i <= n; i++)
		{
			fn = prev1 + prev2;
			prev1 = prev2;
			prev2 = fn;
		}
		
		return fn;
	}
}


int RecurFibonacci(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return RecurFibonacci(n - 1) + RecurFibonacci(n - 2);
}

int main()
{
	// Input      : 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377
	// Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377

	cout << "Input     : ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << i << " ";
	cout << endl;

	// Fibonnacci
	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << Fibonacci(i) << " ";
	cout << endl;

	cout << "Fibonnacci: ";
	for (int i = 0; i < 15; i++)
		cout << setw(3) << RecurFibonacci(i) << " ";
	cout << endl;

	return 0;
}

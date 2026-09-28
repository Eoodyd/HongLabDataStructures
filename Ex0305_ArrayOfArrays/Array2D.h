#pragma once

// 앞 예제와 구분하기 위해 Array2D 라는 이름 사용
// 내용은 Matrix와 동일
class Array2D
{
public:
	Array2D(int num_rows, int num_cols);

	Array2D(const Array2D& b);

	~Array2D();

	void SetValue(int row, int col, float value);

	float GetValue(int row, int col) const;

	Array2D Add(const Array2D& b);

	Array2D Transpose();

	void Print();

private:
	// 2중 포인터: 
	// 연속되는 12개 메모리공간을 얻어야 하는데 여유치 않는 상황을 가정
	// 그렇다면 연속된 4개의 메모리공간을 3개 받으면 되겠지
	
	//`float*`은 float 배열의 주소 *arrays_ 라고 생각하셈
	float** arrays_ = nullptr; 
	int num_rows_ = 0;
	int num_cols_ = 0;
};

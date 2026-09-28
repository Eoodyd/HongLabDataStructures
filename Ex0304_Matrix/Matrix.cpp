#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
	// TODO:
	values_ = new float[num_rows * num_cols]();
	this->num_rows_ = num_rows;
	this->num_cols_ = num_cols;
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix& b)
{
	// TODO:
	memcpy(values_, b.values_, num_cols_ * num_rows_);

	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;
}

Matrix::~Matrix()
{
	// TODO:
	delete[] values_;
	values_ = nullptr;
	num_rows_ = 0;
	num_cols_ = 0;
}

void Matrix::SetValue(int row, int col, float value)
{
	//TODO: 
	values_[row * num_cols_ + col] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	//TODO: 
	return values_[row * num_cols_ + col];
}

Matrix Matrix::Transpose()
{
	Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

	// TODO: 행과 열을 바꾼 행렬. 어짜피 한줄로 저장되어 있으니까 다른 방식으로 행렬 쪼개는 걸로 생각하기

	temp.num_rows_ = num_cols_;
	temp.num_cols_ = num_rows_;

	for (int i = 0; i < num_rows_ * num_cols_; i++)
	{
		temp.values_[i] = values_[i];
	}

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	//행렬 개수가 같다는 가정
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);
	
	// TODO:

	for (int i = 0; i < num_rows_ * num_cols_; i++)
	{
		temp.values_[i] = values_[i] + b.values_[i];
	}

	return temp;
}

void Matrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}

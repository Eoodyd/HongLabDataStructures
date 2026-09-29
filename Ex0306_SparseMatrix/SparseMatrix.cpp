#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	// TODO: 
	terms_ = new MatrixTerm[capacity]();
	num_rows_ = num_rows;
	num_cols_ = num_cols;
	capacity_ = capacity;
	num_terms_ = 0;
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	// TODO:
	if (b.capacity_ <= 0) return;

	terms_ = new MatrixTerm[b.capacity_];
	memcpy(terms_, b.terms_, b.num_terms_ * sizeof(MatrixTerm));

	capacity_ = b.capacity_;
	num_terms_ = b.num_terms_;
	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;
}

SparseMatrix::~SparseMatrix()
{
	// TODO:
	if (!terms_) return;

	delete[] terms_;
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; // value가 0이 아닌 term만 저장

	// TODO:
	// 0이 포함된 방식으로 풀어도 됨
	if (row >= num_rows_ || col >= num_cols_ || row < 0 || col < 0) return;

	for (int i = 0; i < num_terms_; i++)
	{
		if (terms_[i].row == row && terms_[i].col == col)
		{
			terms_[i].value = value;
			return;
		}
	}
	
	if (num_terms_ == capacity_)
	{
		MatrixTerm* temp = new MatrixTerm[capacity_ * 2];
		memcpy(temp, terms_, num_terms_ * sizeof(MatrixTerm));
		capacity_ *= 2;

		MatrixTerm* tt = terms_;
		terms_ = temp;

		delete[] tt;
	}

	terms_[num_terms_].col = col;
	terms_[num_terms_].row = row;
	terms_[num_terms_].value = value;

	num_terms_++;
}

float SparseMatrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	// TODO: key = col + num_cols * row;
	if (row >= num_rows_ || col >= num_cols_ || row < 0 || col < 0) return -1;

	for (int i = 0; i < num_terms_; i++)
	{
		if (terms_[i].row == row && terms_[i].col == col) return terms_[i].value;
	}

	return 0;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의
	
	// TODO:
	for (int i = 0; i < num_terms_; i++)
	{
		temp.terms_[i].row = terms_[i].col;
		temp.terms_[i].col = terms_[i].row;
		temp.terms_[i].value = terms_[i].value;
	}

	temp.num_terms_ = num_terms_;

	return temp;
}

void SparseMatrix::PrintTerms()
{
	for (int i = 0; i < num_terms_; i++)
		cout << "(" << terms_[i].row
		<< ", " << terms_[i].col
		<< ", " << terms_[i].value
		<< ")" << endl;
}

void SparseMatrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}

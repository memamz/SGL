/*
 * Copyright (c) 2018 Mohamed Emam
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 */

#include "matrix4.h"
#include <iostream>

using namespace SGMath;

// Default constructor creates identity matrix
Matrix4::Matrix4()
{
	for(int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (x == y)			// Diagonal
				m[x][y] = 1.0;
			else
				m[x][y] = 0.0;
		}
}

Matrix4::Matrix4(const Matrix4& m2)
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = m2(x, y);
}

Matrix4::~Matrix4() {};

Matrix4& Matrix4::operator= (const Matrix4& m2)
{
	if (this == &m2)
		return (*this);

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = m2(x, y);

	return (*this);
}

Matrix4 Matrix4::operator* (const Matrix4& m2) const
{
	Matrix4 product;

	for(int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			double sum = 0.0;

			for (int j = 0; j < 4; j++)
				sum += m[x][j] * m2(j, y);		// Row of first * column of second

			product(x, y) = sum;
		}

	return product;
}

Matrix4 Matrix4::operator* (const double d)
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] *= d;

	return (*this);
}

Matrix4 Matrix4::operator/ (const double d)
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] /= d;

	return (*this);
}

Matrix4 Matrix4::operator+ (const Matrix4& m2) const
{
	Matrix4 sum;

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			sum(x, y) = m[x][y] + m2(x, y);

	return sum;
}

Matrix4 Matrix4::operator- (const Matrix4& m2) const
{
	Matrix4 diff;

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			diff(x, y) = m[x][y] - m2(x, y);

	return diff;
}

void Matrix4::setToIdentity()
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (x == y)			// Diagonal
				m[x][y] = 1.0;
			else
				m[x][y] = 0.0;
		}
}

void Matrix4::print() const
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (y % 4 == 0)
				std::cout << std::endl;

			std::cout << m[x][y] << " ";
		}

	std::cout << std::endl;
}

Matrix4 operator* (const double d, const SGMath::Matrix4& m)
{
	Matrix4 m2;

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m2(x, y) *= d;

	return m2;
}

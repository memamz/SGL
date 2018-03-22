/*
 * Copyright (c) 2018 Mohamed Emam
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 */

#include "normal.h"
#include <math.h>
#include <iostream>

using namespace SGMath;

Normal::Normal() : x(0.0), y(0.0), z(0.0) {}

Normal::Normal(const double d) : x(d), y(d), z(d) {}

Normal::Normal(const double a, const double b, const double c) : x(a), y(b), z(c) {}

Normal::Normal(const Normal& n) : x(n.x), y(n.y), z(n.z) {}

Normal::Normal(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

Normal::~Normal() {}

Normal& Normal::operator= (const Normal& n)
{
	if (this == &n)
		return (*this);

	x = n.x;
	y = n.y;
	z = n.z;

	return (*this);
}

Normal& Normal::operator= (const Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;

	return (*this);
}

Normal& Normal::operator= (const Point3& p)
{
	x = p.x;
	y = p.y;
	z = p.z;

	return (*this);
}

void Normal::normalize()
{
	double mag = sqrt(x * x + y * y + z * z);
	x /= mag; y /= mag; z /= mag;
}

void Normal::print() const
{
	std::cout << std::endl << x << " " << y << " " << z << " " << std::endl;
}

// Multiply a 4x4 Matrix with 3x1 Normal assuming the last dimension is zero
// Common in 3D as a Normal can't be translated
Normal operator* (const Matrix4& mat, const Normal& n)
{
	return Normal(mat(0, 0) * n.x + mat(0, 1) * n.y + mat(0, 2) * n.z,
	              mat(1, 0) * n.x + mat(1, 1) * n.y + mat(1, 2) * n.z,
	              mat(2, 0) * n.x + mat(2, 1) * n.y + mat(2, 2) * n.z);
}
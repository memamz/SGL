/*
 * Copyright (c) 2018 Mohamed Emam
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 */

#include "vector3.h"
#include "normal.h"
#include "point3.h"
#include <math.h>
#include <iostream>

using namespace SGMath;

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

Vector3::Vector3(const double d) : x(d), y(d), z(d) {}

Vector3::Vector3(const double a, const double b, const double c) : x(a), y(b), z(c) {}

Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

Vector3::Vector3(const Normal& n) : x(n.x), y(n.y), z(n.z) {}

Vector3::Vector3(const Point3& p) : x(p.x), y(p.y), z(p.z) {}

Vector3::~Vector3() {}

Vector3& Vector3::operator= (const Vector3& v)
{
	if (this == &v)
		return (*this);

	x = v.x;
	y = v.y;
	z = v.z;

	return (*this);
}

Vector3& Vector3::operator= (const Normal& n)
{
	x = n.x;
	y = n.y;
	z = n.z;

	return (*this);
}

Vector3& Vector3::operator= (const Point3& p)
{
	x = p.x;
	y = p.y;
	z = p.z;

	return (*this);
}

double Vector3::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::normalize()
{
	double mag = sqrt(x * x + y * y + z * z);
	x /= mag; y /= mag; z /= mag;
	return (*this);
}

void Vector3::print() const
{
	std::cout << std::endl << x << " " << y << " " << z << " " << std::endl;
}

// Multiply a 4x4 Matrix with 3x1 Vector assuming the last dimension is zero
// Common in 3D as a Vector can't be translated
Vector3 operator* (const Matrix4& mat, const Vector3& v)
{
	return Vector3(mat(0,0) * v.x + mat(0, 1) * v.y + mat(0, 2) * v.z,
	               mat(1, 0) * v.x + mat(1, 1) * v.y + mat(1, 2) * v.z,
	               mat(2, 0) * v.x + mat(2, 1) * v.y + mat(2, 2) * v.z);
}
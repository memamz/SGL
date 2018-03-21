#include "point3.h"
#include <math.h>
#include <iostream>

using namespace SGMath;

Point3::Point3() : x(0.0), y(0.0), z(0.0) {}

Point3::Point3(const double d) : x(d), y(d), z(d) {}

Point3::Point3(const double a, const double b, const double c) : x(a), y(b), z(c) {}

Point3::Point3(const Point3& p) : x(p.x), y(p.y), z(p.z) {}

Point3::~Point3() {}

Point3& Point3::operator= (const Point3& p)
{
	if (this == &p)
		return (*this);

	x = p.x;
	y = p.y;
	z = p.z;

	return (*this);
}

double Point3::distance(const Point3& p) const
{
	return sqrt((x - p.x) * (x - p.x)
	          + (y - p.y) * (y - p.y)
	          + (z - p.z) * (z - p.z));
}

void Point3::print() const
{
	std::cout << std::endl << x << " " << y << " " << z << " " << std::endl;
}

// Multiply a 4x4 Matrix with 3x1 Point assuming the last dimension is one
// Common in 3D as a Point can be translated
Point3 operator* (const Matrix4& mat, const Point3& p)
{
	return Point3(mat(0, 0) * p.x + mat(0, 1) * p.y + mat(0, 2) * p.z + mat(0, 3),
	              mat(1, 0) * p.x + mat(1, 1) * p.y + mat(1, 2) * p.z + mat(1, 3),
                  mat(2, 0) * p.x + mat(2, 1) * p.y + mat(2, 2) * p.z + mat(2, 3));
}
/*
 * Copyright (c) 2018 Mohamed Emam
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 */

#include "point2.h"

using namespace SGMath;

Point2::Point2() : x(0.0), y(0.0) { }

Point2::Point2(const double d) : x(d), y(d) { }

Point2::Point2(const double a, const double b) : x(a), y(b) { }

Point2::Point2(const Point2& p) : x(p.x), y(p.y) { }

Point2::~Point2() { }

Point2& Point2::operator= (const Point2& p)
{
	if (this == &p)
		return (*this);

	x = p.x;
	y = p.y;

	return (*this);
}
/*
 * Copyright (c) 2018 Mohamed E. Saleh
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 */

#include "ray.h"

using namespace sgl;

Ray::Ray() : origin(0.0), direction(0.0, 0.0, 1.0) { }

Ray::Ray(const Point3& o, const Vector3& dir) : origin(o), direction(dir) { }

Ray::Ray(const Ray& r) : origin(r.origin), direction(r.direction) { }

Ray::~Ray() { }

Ray& Ray::operator= (const Ray& r)
{
	if (this == &r)
		return (*this);

	origin = r.origin;
	direction = r.direction;

	return (*this);
}


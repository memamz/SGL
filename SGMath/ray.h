/*
 * Copyright (c) 2018 Mohamed Emam
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 *
 * This is a class for ray.
 */

#ifndef SGLRAY_H
#define SGLRAY_H

#include "point3.h"

namespace SGMath
{
	class Ray
	{
	public:
		Point3 origin;
		Vector3 direction;

		// Constructors
		Ray();                                      // Default Constructor
		Ray(const Point3& o, const Vector3& dir);   // Main Constructor
		Ray(const Ray& r);                          // Copy Constructor
		~Ray();                                     // Destructor

		// Operators
		Ray& operator= (const Ray& r);              // Assignment Operator
	};
}

#endif
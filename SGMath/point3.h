/*
 * Copyright (c) 2018 Mohamed Emam
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 *
 * This is a class for a 3D Point, It can be used alongside Normal and Vector3.
 * If you prefer a generic vector class for all positions and vectors check the vector4.h file.
 */

#ifndef SGLPOINT3_H
#define SGLPOINT3_H

#include "vector3.h"

namespace SGMath
{
	class Point3
	{
	public:
		double x, y, z;

		// Constructors
		Point3();                                                  // Default Constructor
		Point3(const double d);                                    // From 1 value
		Point3(const double x, const double y, const double z);    // From 3 values
		Point3(const Point3& p);                                   // Copy Constructor
		~Point3();                                                 // Destructor

		// Operators
		Point3& operator= (const Point3& p);                       // Assignment operator
		Point3 operator* (const double c) const;                   // Point-scalar multiplication
		Point3 operator/ (const double c) const;                   // Point-scalar division
		Point3 operator+ (const Vector3& v) const;                 // Point-vector addition
		Point3 operator- (const Vector3& v) const;                 // Point-vector subtraction
		Vector3 operator- (const Point3& p) const;                 // Point-Point subtraction
		Point3 operator- () const;                                 // Returns negated point
		Point3& operator+= (const Vector3& v);                     // Add and assign

		// Functions
		double distance(const Point3& p) const;                    // Get distance between 2 points
		double d2(const Point3& p) const;                          // Get distance squared
		void print() const;                                        // For Debugging
	};
}

inline SGMath::Point3 SGMath::Point3::operator* (const double c) const { return SGMath::Point3(x * c, y * c, z * c); }
inline SGMath::Point3 SGMath::Point3::operator/ (const double c) const { return SGMath::Point3(x / c, y / c, z / c); }
inline SGMath::Point3 SGMath::Point3::operator+ (const SGMath::Vector3& v) const { return SGMath::Point3(x + v.x, y + v.y, z + v.z); }
inline SGMath::Point3 SGMath::Point3::operator- (const SGMath::Vector3& v) const { return SGMath::Point3(x - v.x, y - v.y, z - v.z); }
inline SGMath::Vector3 SGMath::Point3::operator- (const SGMath::Point3& p) const { return SGMath::Vector3(x - p.x, y - p.y, z - p.z); }
inline SGMath::Point3 SGMath::Point3::operator- () const { return SGMath::Point3(-x, -y, -z); }
inline SGMath::Point3& SGMath::Point3::operator+= (const SGMath::Vector3& v) { x += v.x; y += v.y; z += v.z; return(*this); }

inline double SGMath::Point3::d2(const SGMath::Point3& p) const
{
	return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z);
}

// Non-member Functions
// Scalar-point multiplication
inline SGMath::Point3 operator* (const double a, const SGMath::Point3& p) { return SGMath::Point3(a * p.x, a * p.y, a * p.z); }
// Matrix 4D-vector 3D multiplication
SGMath::Point3 operator* (const SGMath::Matrix4& mat, const SGMath::Point3& p);

#endif
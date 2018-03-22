/*
 * Copyright (c) 2018 Mohamed Emam
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 *
 * This is a class for a 3D Vector, It can be used alongside Point3 and Normal.
 * If you prefer a generic vector class for all positions and vectors check the vector4.h file.
 */

#ifndef SGLVECTOR3_H
#define SGLVECTOR3_H

#include "matrix4.h"

namespace SGMath
{
	class Normal;
	class Point3;

	class Vector3
	{
	public:
		double x, y, z;

		// Constructors
		Vector3();                                                  // Default Constructor
		Vector3(const double d);                                    // From 1 value
		Vector3(const double x, const double y, const double z);    // From 3 values
		Vector3(const Vector3& v);                                  // Copy Constructor
		Vector3(const Normal& n);                                   // From Normal
		Vector3(const Point3& n);                                   // From Point
		~Vector3();                                                 // Destructor

		// Operators
		Vector3& operator= (const Vector3& v);                      // Assignment operator
		Vector3& operator= (const Normal& n);                       // Assign from normal
		Vector3& operator= (const Point3& p);                       // Assign from point
		Vector3 operator* (const double c) const;                   // Vector-scalar multiplication
		Vector3 operator/ (const double c) const;                   // Vector-scalar division
		Vector3 operator+ (const Vector3& v) const;                 // Vector-vector addition
		Vector3 operator- (const Vector3& v) const;                 // Vector-vector subtraction
		Vector3 operator- () const;                                 // Returns negated vector
		Vector3& operator+= (const Vector3& v);                     // Add and assign

		// Functions
		double magnitude() const;                                   // Get Magnitude
		double magsquared() const;                                  // Get Magnitude squared
		double dot(const Vector3& v) const;                         // Dot product
		Vector3 cross(const Vector3& v) const;                      // Cross product
		Vector3& normalize();                                       // Normalize the vector
		void print() const;                                         // For Debugging
	};
}

inline SGMath::Vector3 SGMath::Vector3::operator* (const double c) const { return SGMath::Vector3(x * c, y * c, z * c); }
inline SGMath::Vector3 SGMath::Vector3::operator/ (const double c) const { return SGMath::Vector3(x / c, y / c, z / c); }
inline SGMath::Vector3 SGMath::Vector3::operator+ (const SGMath::Vector3& v) const { return SGMath::Vector3(x + v.x, y + v.y, z + v.z); }
inline SGMath::Vector3 SGMath::Vector3::operator- (const SGMath::Vector3& v) const { return SGMath::Vector3(x - v.x, y - v.y, z - v.z); }
inline SGMath::Vector3 SGMath::Vector3::operator- () const { return SGMath::Vector3(-x, -y, -z); }
inline SGMath::Vector3& SGMath::Vector3::operator+= (const SGMath::Vector3& v) { x += v.x; y += v.y; z += v.z; return(*this); }

inline double SGMath::Vector3::magsquared() const { return x*x + y*y + z*z; }
inline double SGMath::Vector3::dot(const SGMath::Vector3& v) const { return x*v.x + y*v.y + z*v.z; }
inline SGMath::Vector3 SGMath::Vector3::cross(const SGMath::Vector3& v) const { return SGMath::Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

// Non-member Functions
// Scalar-vector multiplication
inline SGMath::Vector3 operator* (const double a, const SGMath::Vector3& v) { return SGMath::Vector3(a * v.x, a * v.y, a * v.z); }
// Matrix 4D-vector 3D multiplication
SGMath::Vector3 operator* (const SGMath::Matrix4& mat, const SGMath::Vector3& v);

#endif
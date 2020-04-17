/*
 * Copyright (c) 2018 Mohamed E. Saleh
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 *
 * This is a class for a 3D Vector, It can be used alongside Point3 and Normal.
 * If you prefer a generic vector class for all positions and vectors check the vector4.h file.
 */

#ifndef SGLVECTOR3_H
#define SGLVECTOR3_H

#include "matrix4.h"

namespace sgl
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
		bool operator== (const Vector3& v) const;
		bool operator!= (const Vector3& v) const;

		// Functions
		double magnitude() const;                                   // Get Magnitude
		double magsquared() const;                                  // Get Magnitude squared
		double dot(const Vector3& v) const;                         // Dot product
		Vector3 cross(const Vector3& v) const;                      // Cross product
		Vector3& normalize();                                       // Normalize the vector
		void print() const;                                         // For Debugging
	};
}

inline sgl::Vector3 sgl::Vector3::operator* (const double c) const { return sgl::Vector3(x * c, y * c, z * c); }
inline sgl::Vector3 sgl::Vector3::operator/ (const double c) const { return sgl::Vector3(x / c, y / c, z / c); }
inline sgl::Vector3 sgl::Vector3::operator+ (const sgl::Vector3& v) const { return sgl::Vector3(x + v.x, y + v.y, z + v.z); }
inline sgl::Vector3 sgl::Vector3::operator- (const sgl::Vector3& v) const { return sgl::Vector3(x - v.x, y - v.y, z - v.z); }
inline sgl::Vector3 sgl::Vector3::operator- () const { return sgl::Vector3(-x, -y, -z); }
inline sgl::Vector3& sgl::Vector3::operator+= (const sgl::Vector3& v) { x += v.x; y += v.y; z += v.z; return(*this); }
//std::ostream& operator<<(std::ostream& stream, const sgl::Vector3& v);

inline double sgl::Vector3::magsquared() const { return x*x + y*y + z*z; }
inline double sgl::Vector3::dot(const sgl::Vector3& v) const { return x*v.x + y*v.y + z*v.z; }
inline sgl::Vector3 sgl::Vector3::cross(const sgl::Vector3& v) const { return sgl::Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

// Non-member Functions
// Scalar-vector multiplication
inline sgl::Vector3 operator* (const double a, const sgl::Vector3& v) { return sgl::Vector3(a * v.x, a * v.y, a * v.z); }
// Matrix 4D-vector 3D multiplication
sgl::Vector3 operator* (const sgl::Matrix4& mat, const sgl::Vector3& v);

#endif
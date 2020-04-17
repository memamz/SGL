/*
 * Copyright (c) 2018 Mohamed E. Saleh
 * The code is licensed under the MIT License.
 * You can check the file LICENSE for the full license.
 *
 * This is a class for a 3D Normal, It can be used alongside Point3 and Vector3.
 * If you prefer a generic vector class for all positions and vectors check the vector4.h file.
 */

#ifndef SGLNORMAL_H
#define SGLNORMAL_H

#include "point3.h"

namespace sgl
{
	class Normal
	{
	public:
		double x, y, z;

		// Constructors
		Normal();                                                  // Default Constructor
		Normal(const double d);                                    // From 1 value
		Normal(const double x, const double y, const double z);    // From 3 values
		Normal(const Normal& n);                                   // Copy Constructor
		Normal(const Vector3& n);                                  // From Vector
		~Normal();                                                 // Destructor

		// Operators
		Normal& operator= (const Normal& n);                       // Assignment operator
		Normal& operator= (const Vector3& n);                      // Assign from vector
		Normal& operator= (const Point3& p);                       // Assign from point
		Normal operator* (const double c) const;                   // Normal-scalar multiplication
		Normal operator/ (const double c) const;                   // Normal-scalar division
		Normal operator+ (const Normal& n) const;                  // Normal-normal addition
		Normal operator- (const Normal& n) const;                  // Normal-normal subtraction
		Normal operator- () const;                                 // Returns negated normal
		Normal& operator+= (const Normal& n);                      // Add and assign

		// Functions
		double dot(const Vector3& v) const;                        // Dot product
		void normalize();                                          // Normalize the Normal
		void print() const;                                        // For Debugging
	};
}

inline sgl::Normal sgl::Normal::operator* (const double c) const { return sgl::Normal(x * c, y * c, z * c); }
inline sgl::Normal sgl::Normal::operator/ (const double c) const { return sgl::Normal(x / c, y / c, z / c); }
inline sgl::Normal sgl::Normal::operator+ (const sgl::Normal& n) const { return sgl::Normal(x + n.x, y + n.y, z + n.z); }
inline sgl::Normal sgl::Normal::operator- (const sgl::Normal& n) const { return sgl::Vector3(x - n.x, y - n.y, z - n.z); }
inline sgl::Normal sgl::Normal::operator- () const { return sgl::Normal(-x, -y, -z); }
inline sgl::Normal& sgl::Normal::operator+= (const sgl::Normal& n) { x += n.x; y += n.y; z += n.z; return(*this); }

inline double sgl::Normal::dot(const sgl::Vector3& v) const { return x*v.x + y*v.y + z*v.z; }

// Non-member Functions
// Scalar-normal multiplication
inline sgl::Normal operator* (const double a, const sgl::Normal& n) { return sgl::Normal(a * n.x, a * n.y, a * n.z); }
inline sgl::Vector3 operator+ (const sgl::Vector3 v, const sgl::Normal& n) { return sgl::Vector3(v.x + n.x, v.y + n.y, v.z + n.z); }
inline sgl::Vector3 operator- (const sgl::Vector3 v, const sgl::Normal& n) { return sgl::Vector3(v.x - n.x, v.y - n.y, v.z - n.z); }
inline double dot(const sgl::Vector3 v, const sgl::Normal& n) { return v.x*n.x + v.y*n.y + v.z*n.z; }
// Matrix 4D-vector 3D multiplication
sgl::Normal operator* (const sgl::Matrix4& mat, const sgl::Normal& n);

#endif
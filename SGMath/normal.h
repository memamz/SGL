#ifndef SGLNORMAL_H
#define SGLNORMAL_H

#include "point3.h"

namespace SGMath
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

inline SGMath::Normal SGMath::Normal::operator* (const double c) const { return SGMath::Normal(x * c, y * c, z * c); }
inline SGMath::Normal SGMath::Normal::operator/ (const double c) const { return SGMath::Normal(x / c, y / c, z / c); }
inline SGMath::Normal SGMath::Normal::operator+ (const SGMath::Normal& n) const { return SGMath::Normal(x + n.x, y + n.y, z + n.z); }
inline SGMath::Normal SGMath::Normal::operator- (const SGMath::Normal& n) const { return SGMath::Vector3(x - n.x, y - n.y, z - n.z); }
inline SGMath::Normal SGMath::Normal::operator- () const { return SGMath::Normal(-x, -y, -z); }
inline SGMath::Normal& SGMath::Normal::operator+= (const SGMath::Normal& n) { x += n.x; y += n.y; z += n.z; return(*this); }

inline double SGMath::Normal::dot(const SGMath::Vector3& v) const { return x*v.x + y*v.y + z*v.z; }

// Non-member Functions
// Scalar-normal multiplication
inline SGMath::Normal operator* (const double a, const SGMath::Normal& n) { return SGMath::Normal(a * n.x, a * n.y, a * n.z); }
inline SGMath::Vector3 operator+ (const SGMath::Vector3 v, const SGMath::Normal& n) { return SGMath::Vector3(v.x + n.x, v.y + n.y, v.z + n.z); }
inline SGMath::Vector3 operator- (const SGMath::Vector3 v, const SGMath::Normal& n) { return SGMath::Vector3(v.x - n.x, v.y - n.y, v.z - n.z); }
inline double dot(const SGMath::Vector3 v, const SGMath::Normal& n) { return v.x*n.x + v.y*n.y + v.z*n.z; }
// Matrix 4D-vector 3D multiplication
SGMath::Normal operator* (const SGMath::Matrix4& mat, const SGMath::Normal& n);

#endif
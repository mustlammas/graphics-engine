#include "stdafx.h"
#include "Plane.h"
#include "Point.h"
#include "Vector.h"

namespace ge {

	Plane::Plane(Point a, Point b, Point c, Point d)
		: a(a), b(b), c(c), d(d)
	{
	}

	Vector Plane::getNormal()
	{
		// Get two vectors
		Vector v1 = Vector(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ());
		Vector v2 = Vector(c.getX() - a.getX(), c.getY() - a.getY(), c.getZ() - a.getZ());

		// Cross product formula: Av x Bv = <AyBz - AzBy, AzBx - AxBz, AxBy - AyBx>
		float x = v1.getY() * v2.getZ() - v1.getZ() * v2.getY();
		float y = v1.getZ() * v2.getX() - v1.getX() * v2.getZ();
		float z = v1.getX() * v2.getY() - v1.getY() * v2.getX();
		return Vector(x, y, z);
	}

	Point Plane::getA() {
		return a;
	}

	Point Plane::getB() {
		return b;
	}

	Point Plane::getC() {
		return c;
	}

	Point Plane::getD() {
		return d;
	}

}
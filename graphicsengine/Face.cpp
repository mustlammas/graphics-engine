#include "stdafx.h"
#include "Face.h"
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>

namespace ge {

	Face::Face(Point a, Point b, Point c)
		: a(a), b(b), c(c)
	{
	}

	std::string Face::str() {
		std::ostringstream buffer;
		buffer << "Face(" << this->a.str() << " -> " << this->b.str() << " -> " << this->c.str() << ")";
		return buffer.str();
	}

	Point Face::getA() {
		return a;
	}

	Point Face::getB() {
		return b;
	}

	Point Face::getC() {
		return c;
	}

	Vector Face::getNormal() {
		// Get two vectors
		Vector v1 = Vector(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ());
		Vector v2 = Vector(c.getX() - a.getX(), c.getY() - a.getY(), c.getZ() - a.getZ());

		// Cross product formula: Av x Bv = <AyBz - AzBy, AzBx - AxBz, AxBy - AyBx>
		float x = v1.getY() * v2.getZ() - v1.getZ() * v2.getY();
		float y = v1.getZ() * v2.getX() - v1.getX() * v2.getZ();
		float z = v1.getX() * v2.getY() - v1.getY() * v2.getX();

		Vector v = Vector(x, y, z);
		Vector unitVector = v.scale(1 / v.getMagnitude());
		return unitVector;
	}

	bool Face::containsPoint(Point p) {
		Vector ab = Vector(a, b);
		Vector bc = Vector(b, c);
		Vector ca = Vector(c, a);
		
		// Check the barymetric coordinate of A
		Vector abProjectedOnAC = ab.projectOn(bc);
		Vector normalOfBC = ab.minus(abProjectedOnAC);
		float baryA = 1 - (normalOfBC.dotProduct(Vector(a, p)) / normalOfBC.dotProduct(ab));

		// Check the barymetric coordinate of B
		Vector bcProjectedOnCA = bc.projectOn(ca);
		Vector normalOfCA = bcProjectedOnCA.negate().minus(bc.negate()).negate();
		float baryB = 1 - (normalOfCA.dotProduct(Vector(b, p)) / normalOfCA.dotProduct(bc));

		// Check the barymetric coordinate of C
		Vector caProjectionOnAB = ca.projectOn(ab);
		Vector normalOfBA = ca.minus(caProjectionOnAB);
		float baryC = 1 - (normalOfBA.dotProduct(Vector(c, p)) / normalOfBA.dotProduct(ca));

		bool aIntersects = baryA >= 0 && baryA <= 1;
		bool bIntersects = baryB >= 0 && baryB <= 1;
		bool cIntersects = baryC >= 0 && baryC <= 1;
		return aIntersects && bIntersects && cIntersects;
	}

}
#include "stdafx.h"
#include "Vector.h"
#include "Point.h"
#include <string>
#include <sstream>
#include <math.h>

namespace ge {

	Vector::Vector(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}

	Vector::Vector(Point a, Point b)
		: x(b.getX() - a.getX()), y(b.getY() - a.getY()), z(b.getZ() - a.getZ())
	{
	}

	std::string Vector::str() {
		std::ostringstream buffer;
		buffer << "(" << x << ", " << y << ", " << z << ")";
		return buffer.str();
	}

	float Vector::getX() {
		return x;
	}

	float Vector::getY() {
		return y;
	}

	float Vector::getZ() {
		return z;
	}

	/*
	The dot product indicates how much overlap there is between all the axis of the two vectors.
	*/
	float Vector::dotProduct(Vector v) {
		// Dot product formula: Av . Bv = Ax * Bx + Ay * By + Az * Bz
		return x * v.getX() + y * v.getY() + z * v.getZ();
	}

	Vector Vector::scale(float k) {
		return Vector(k * x, k * y, k * z);
	}

	Point Vector::fromPoint(Point p) {
		return Point(x + p.getX(), y + p.getY(), z + p.getZ());
	}

	float Vector::getMagnitude() {
		return sqrtf(x * x + y * y + z * z);
	}

	Vector Vector::plus(Vector v) {
		return Vector(x + v.getX(), y + v.getY(), z + v.getZ());
	}

	Vector Vector::minus(Vector v) {
		return Vector(x - v.getX(), y - v.getY(), z - v.getZ());
	}

	Vector Vector::projectOn(Vector v) {
		float ac = this->dotProduct(v);
		float vv = v.dotProduct(v);
		float k = ac / vv;
		return v.scale(k);
	}

	Vector Vector::negate() {
		return Vector(-x, -y, -z);
	}

	Point Vector::asPoint() {
		return Point(x, y, z);
	}
}
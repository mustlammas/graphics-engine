#pragma once
#include "Point.h"
#include <string>

namespace ge {

	class Vector
	{
	private:
		float x, y, z;
	public:
		Vector(float a, float b, float c);
		Vector(Point a, Point b);
		std::string str();
		float getX();
		float getY();
		float getZ();
		float dotProduct(Vector v);
		Vector scale(float k);
		Point fromPoint(Point p);
		float getMagnitude();
		Vector plus(Vector v);
		Vector minus(Vector v);
		Vector projectOn(Vector v);
		Vector negate();
		Point asPoint();
	};

}
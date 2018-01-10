#pragma once
#include "Point.h"
#include "Vector.h"

namespace ge {
	class Face
	{
	private:

		Point a, b, c;

	public:
		Face(Point a, Point b, Point c);
		std::string str();
		Point getA();
		Point getB();
		Point getC();
		Vector getNormal();
		bool containsPoint(Point p);
	};
}
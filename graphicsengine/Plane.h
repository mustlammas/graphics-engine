#pragma once
#include "Point.h"
#include "Vector.h"

namespace ge {

	class Plane
	{
	private:
		Point a, b, c, d;
	public:
		Plane(Point a, Point b, Point c, Point d);
		Vector getNormal();
		Point getA();
		Point getB();
		Point getC();
		Point getD();
	};

}
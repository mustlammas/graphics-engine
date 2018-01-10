#include "stdafx.h"
#include "Point.h"
#include <string>
#include <sstream>
#include <math.h>

namespace ge {

		Point::Point() 
		{
		}

		Point::Point(float x, float y, float z)
			: x(x), y(y), z(z)
		{
		}

		std::string Point::str() {
			std::ostringstream buffer;
			buffer << "(" << x << ", " << y << ", " << z << ")";
			return buffer.str();
		}

		float Point::distanceTo(Point p) {
			float xDist = p.getX() - x;
			float yDist = p.getY() - y;
			float zDist = p.getZ() - z;

			float xyDist = std::sqrtf( (xDist * xDist) + (yDist * yDist) );
			float xyzDist = std::sqrtf( (xyDist * xyDist) + (zDist * zDist) );

			return xyzDist;
		}

		float Point::getX() {
			return x;
		}

		float Point::getY() {
			return y;
		}

		float Point::getZ() {
			return z;
		}

}

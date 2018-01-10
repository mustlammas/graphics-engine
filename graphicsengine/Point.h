#pragma once
#include <string>

namespace ge {
	class Point
	{
	private:

		float x, y, z;

	public:
		Point();
		Point(float x, float y, float z);
		std::string str();
		float distanceTo(Point p);
		float getX();
		float getY();
		float getZ();
	};
}
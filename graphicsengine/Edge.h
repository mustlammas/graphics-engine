#pragma once
#include "Point.h"
#include <string>
#include "Face.h"

namespace ge {
	class Edge
	{
	private:

		Point a, b;

	public:
		Edge(Point a, Point b);
		std::string str();
		float weightedAvg(float weight, float a, float b);
		Point getIntersection(Face f);
	};
}

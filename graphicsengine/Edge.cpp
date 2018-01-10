#include "stdafx.h"
#include "Edge.h"
#include <string>
#include <sstream>
#include "Vector.h"
#include <iostream>

/*
I use member initalization so that I can omit default constructors.
*/
namespace ge {

	Edge::Edge(Point a, Point b)
		: a(a), b(b)
	{
	}

	std::string Edge::str() {
		std::ostringstream buffer;
		buffer << "Edge(" << a.str() << " -> " << b.str() << ", "")";
		return buffer.str();
	}

	float Edge::weightedAvg(float weight, float a, float b) {
		// Formula: R(t) = (1 - t) * a + (t * b), where t is the weight.
		return (1 - weight) * a + (weight * b);
	}

	Point Edge::getIntersection(Face f) {
		Vector cameraToFace = Vector(a, f.getA());
		Vector cameraToPixel = Vector(a, b);
		Vector faceNormal = f.getNormal();
		Point camera = a;

		float k = cameraToFace.dotProduct(faceNormal) / cameraToPixel.dotProduct(faceNormal);
		Vector scaledVector = cameraToPixel.scale(k);
		return scaledVector.fromPoint(camera);
	}

}
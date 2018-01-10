#include "stdafx.h"
#include "Camera.h"
#include "Point.h"
#include "Vector.h"
#include "Plane.h"
#include "Edge.h"
#include <iostream>

namespace ge {

	// Image plane points are defined in local speace (relative to camera position)
	Camera::Camera(Point location, Vector direction)
		: location(location), 
		direction(direction), 
		upperLeft(Point(1, 1, 1)), 
		upperRight(Point(1, -1, 1)),
		lowerRight(Point(1, -1, -1)),
		lowerLeft(Point(1, 1, -1))
	{
	}

	Plane Camera::getImagePlane() {
		Vector ul = Vector(location.getX() + upperLeft.getX(), location.getY() + upperLeft.getY(), location.getZ() + upperLeft.getZ());
		Vector ll = Vector(location.getX() + lowerLeft.getX(), location.getY() + lowerLeft.getY(), location.getZ() + lowerLeft.getZ());
		Vector lr = Vector(location.getX() + lowerRight.getX(), location.getY() + lowerRight.getY(), location.getZ() + lowerRight.getZ());
		Vector ur = Vector(location.getX() + upperRight.getX(), location.getY() + upperRight.getY(), location.getZ() + upperRight.getZ());

		Plane imagePlane = Plane(ul.asPoint(), ur.asPoint(), lr.asPoint(), ll.asPoint());
		return imagePlane;
	}

	void Camera::setPixelLocations(Point (&pixelLocations)[PIXELS_V][PIXELS_H]) {
		Plane imagePlane = getImagePlane();
		Point a = imagePlane.getA();
		Point b = imagePlane.getB();
		Point d = imagePlane.getD();
		Vector ab = Vector(a, b);
		Vector ad = Vector(a, d);
		for (int y = 0; y < PIXELS_V; y++) {
			for (int x = 0; x < PIXELS_H; x++) {
				float xScalar = ((float) x + 0.5) / PIXELS_H;
				Vector xVector = ab.scale(xScalar);
				float yScalar = ((float) y + 0.5) / PIXELS_V;
				Vector yVector = ad.scale(yScalar);
				Vector xyVector = Vector(a.getX(), a.getY(), a.getZ()).plus(xVector).plus(yVector);
				Point p = Point(xyVector.getX(), xyVector.getY(), xyVector.getZ());
				pixelLocations[y][x] = p;
			}
		}
	}

	Point Camera::getLocation() {
		return location;
	}

}

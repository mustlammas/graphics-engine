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

	float Camera::getImagePlaneLength() {
		return upperLeft.distanceTo(upperRight);
	}

	float Camera::getImagePlaneHeight() {
		return lowerLeft.distanceTo(upperLeft);
	}

	void Camera::setPixelLocations(Point (&pixelLocations)[PIXELS_V][PIXELS_H]) {
		float imagePlaneLength = getImagePlaneLength();
		float imagePlaneHeight = getImagePlaneHeight();
		float pxDistH = imagePlaneLength / PIXELS_H;
		float pxDistV = imagePlaneHeight / PIXELS_V;
		float halfPixelWidth = pxDistH / 2;

		for (int y = 0; y < PIXELS_V; y++) {
			for (int x = 0; x < PIXELS_H; x++) {
				float xx = getImagePlane().getA().getX(); // Hard coded x for now
				float yy = getImagePlane().getA().getY() - (x * pxDistV + halfPixelWidth);
				float zz = getImagePlane().getA().getZ() - (y * pxDistH + halfPixelWidth);
				Point p = Point(xx, yy, zz);
				pixelLocations[y][x] = p;
			}
		}
	}

	Point Camera::getLocation() {
		return location;
	}

}

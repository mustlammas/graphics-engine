#pragma once
#include "Point.h"
#include "Vector.h"
#include "Plane.h"

namespace ge {

	const int PIXELS_H = 30;
	const int PIXELS_V = 30;

	class Camera
	{
	private:
		Point location;
		Vector direction;
		Point upperLeft, upperRight, lowerRight, lowerLeft;
	public:
		Camera(Point location, Vector direction);
		Plane getImagePlane();
		float getImagePlaneLength();
		float getImagePlaneHeight();
		void setPixelLocations(Point(&pixelLocations)[PIXELS_V][PIXELS_H]);
		Point getLocation();
	};
}
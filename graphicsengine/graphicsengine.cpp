#include "stdafx.h"
#include "Point.h"
#include "Edge.h"
#include "Face.h"
#include <iostream>
#include "Camera.h"
#include "Plane.h"
#include "Scene.h"

using namespace ge;

/*
TODO: 
1. Upload to github
2. Make sure the camera can be moved around and the rendering still works.
*/
int main()
{
	Point a = Point(3, 2, 0);
	Point b = Point(3, 0, 2);
	Point c = Point(3, -2, 0);
	Face face = Face(a, b, c);

	Point cameraLocation = Point(0, 0, 0);
	Vector cameraDirection = Vector(1, 0, 0);
	Camera camera = Camera(cameraLocation, cameraDirection);

	Scene scene = Scene(camera, face);
	scene.render();

	return 0;
}


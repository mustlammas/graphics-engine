#include "stdafx.h"
#include "Point.h"
#include "Edge.h"
#include "Face.h"
#include <iostream>
#include "Camera.h"
#include "Plane.h"
#include "Scene.h"
#include <chrono>
#include <thread>

using namespace ge;

/*
TODO: 
- Make sure the camera can be moved around and the rendering still works.
*/
int main()
{
	Point a = Point(5, 2, 0);
	Point b = Point(5, 0, 2);
	Point c = Point(5, -2, 0);
	Face face = Face(a, b, c);

	Point cameraLocation = Point(0, 0, 0);
	Vector cameraDirection = Vector(1, 0, 0);

	cameraLocation = Point(0, 0, 0);

	// TODO: rotate the camera
	for (int i = 0; i < 10; i++) {
		//Point cameraLocation = Point(i, 0, 0);
		//Vector cameraDirection = Vector(1, 0, 0);
		Camera camera = Camera(cameraLocation, cameraDirection);
		Scene scene = Scene(camera, face);
		scene.render();
		break;
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	return 0;
}


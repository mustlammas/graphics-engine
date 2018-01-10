#include "stdafx.h"
#include "Scene.h"
#include "Camera.h"
#include "Face.h"
#include "Edge.h"
#include <iostream>

namespace ge {

	Scene::Scene(Camera camera, Face face)
		: camera(camera), face(face)
	{
	}

	void Scene::render() {
		Point pixelLocations[PIXELS_V][PIXELS_H];
		camera.setPixelLocations(pixelLocations);
		for (int y = 0; y < PIXELS_V; y++) {
			for (int x = 0; x < PIXELS_H; x++) {
				Point pxLocation = pixelLocations[y][x];
				Edge ray = Edge(camera.getLocation(), pxLocation);
				Point i = ray.getIntersection(face);
				bool intersects = face.containsPoint(i);
				if (intersects) {
					float distanceToCamera = camera.getLocation().distanceTo(i);
					float distanceToImagePlane = pxLocation.distanceTo(i);
					// Check that the intersection point is not behind the camera
					if (distanceToCamera > distanceToImagePlane) {
						std::cout << " . ";
						continue;
					}
				}
				std::cout << " 0 ";
			}
			std::cout << "\n";
		}
	}

}
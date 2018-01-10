#pragma once
#include "Camera.h"
#include "Face.h"

namespace ge {

	class Scene
	{
	private:
		Camera camera;
		Face face;
	public:
		Scene(Camera camera, Face face);
		void render();
	};

}
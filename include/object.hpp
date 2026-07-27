#pragma once
#include "main.hpp"

class Object
{
public:
	Object3d m_object;
	Object2d m_objectProjected;

	Object(Object3d, Object2d);

	void coordinatesLog();
	void realCoordinatesLog();
	void matrixOfProjection();
	void projectObject();
	void projectPolygon(Polygon2d &);
	void renderObject(SDL_Renderer *) const;
	void renderPolygon(SDL_Renderer *, Polygon2d polygo, Polygon3d) const;
	void update();
};

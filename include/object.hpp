#pragma once
#include "main.hpp"

class Object {
public:
	Object3d m_object;
	Object2d m_object_projected;

	Object(Object3d, Object2d);

	void coordinates_log();
	void real_coordinates_log();
	void matrix_of_projection();
	void project_object();
	void project_polygon(Polygon2d &);
	void render_object(SDL_Renderer *) const;
	void render_polygon(SDL_Renderer *, Polygon2d polygo, Polygon3d) const;
	void update();
};

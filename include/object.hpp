#pragma once
#include "main.hpp"

class Object {
public:
	Object3d m_object;
	Object2d m_object_projected;

	Object(Object3d);

	void coordinates_log() const;
	void real_coordinates_log() const;
	void matrix_of_projection();
	void project_object();
	void project_polygon(Polygon2d &);
	void render_object(SDL_Renderer *) const;
	void render_polygon(SDL_Renderer *, const Polygon2d, const Polygon3d) const;
	void update();
};

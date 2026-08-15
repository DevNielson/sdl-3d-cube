#pragma once
#include "utils.hpp"

class Object
{
private:
	glm::vec3 m_position;
	utils::Object3d m_object;
	utils::Object2d m_object_projected;

public:
	Object(const glm::vec3, const utils::Object3d);

public:
	void real_coordinates_log() const;
	void coordinates_log() const;

public:
	void translation();
	void project_object();
	void project_polygon(utils::Polygon2d &);

public:
	void render_object(SDL_Renderer *) const;
	void render_polygon(SDL_Renderer *, const utils::Polygon2d, const utils::Polygon3d) const;

public:
	void update();
};

#include "object.hpp"

Object::Object(Object3d obj3d)
	: m_object{ obj3d },
	  m_object_projected{ std::vector<Polygon2d>{ m_object.polygons.size() } }
{
	matrix_of_projection();
	project_object();

	coordinates_log();
	real_coordinates_log();
}

void Object::coordinates_log() const {
	std::println("{:*^20}", '*');
	std::println("Coordinates x, y, z");
	std::println("{:*^20}", '*');

	for (Polygon3d polygon : m_object.polygons) {
		std::println("vertex0 x = {}", polygon.vertex.at(0).x);
		std::println("vertex0 y = {}", polygon.vertex.at(0).y);
		std::println("vertex0 z = {}", polygon.vertex.at(0).z);
		std::println();

		std::println("vertex1 x = {}", polygon.vertex.at(1).x);
		std::println("vertex1 y = {}", polygon.vertex.at(1).y);
		std::println("vertex1 z = {}", polygon.vertex.at(1).z);
		std::println();

		std::println("vertex2 x = {}", polygon.vertex.at(2).x);
		std::println("vertex2 y = {}", polygon.vertex.at(2).y);
		std::println("vertex2 z = {}", polygon.vertex.at(2).z);
	}
	std::println("{:*^20}\n", '*');
}

void Object::real_coordinates_log() const {
	std::println("{:*^20}", '*');
	std::println("Real Coordinates x, y");
	std::println("{:*^20}", '*');

	for (Polygon2d polygon : m_object_projected.polygons) {
		std::println("vertex0 x = {}", polygon.vertex.at(0).x);
		std::println("vertex0 y = {}\n", polygon.vertex.at(0).y);

		std::println("vertex1 x = {}", polygon.vertex.at(1).x);
		std::println("vertex1 y = {}\n", polygon.vertex.at(1).y);

		std::println("vertex2 x = {}", polygon.vertex.at(2).x);
		std::println("vertex2 y = {}", polygon.vertex.at(2).y);
	}
	std::println("{:*^20}\n", '*');
}

void Object::update() {
	const bool *key_state{ SDL_GetKeyboardState(nullptr) };
	if (key_state[SDL_SCANCODE_W]) {
		for (Polygon3d &polygon : m_object.polygons) {
			for (Vec3d &vertex : polygon.vertex) {
				vertex.z += 0.3f;
			}
		}
		matrix_of_projection();
		project_object();
	}
	if (key_state[SDL_SCANCODE_A]) {
		for (Polygon3d &polygon : m_object.polygons) {
			for (Vec3d &vertex : polygon.vertex) {
				vertex.x -= 0.3f;
			}
		}
		matrix_of_projection();
		project_object();
	}
	if (key_state[SDL_SCANCODE_S]) {
		for (Polygon3d &polygon : m_object.polygons) {
			for (Vec3d &vertex : polygon.vertex) {
				vertex.z -= 0.3f;
			}
		}
		matrix_of_projection();
		project_object();
	}
	if (key_state[SDL_SCANCODE_D]) {
		for (Polygon3d &polygon : m_object.polygons) {
			for (Vec3d &vertex : polygon.vertex) {
				vertex.x += 0.3f;
			}
		}
		matrix_of_projection();
		project_object();
	}
	if (key_state[SDL_SCANCODE_SPACE]) {
		for (Polygon3d &polygon : m_object.polygons) {
			for (Vec3d &vertex : polygon.vertex) {
				vertex.y += 0.3f;
			}
		}
		matrix_of_projection();
		project_object();
	}
	if (key_state[SDL_SCANCODE_LSHIFT]) {
		for (Polygon3d &polygon : m_object.polygons) {
			for (Vec3d &vertex : polygon.vertex) {
				vertex.y -= 0.3f;
			}
		}
		matrix_of_projection();
		project_object();
	}
}

void Object::matrix_of_projection() {
	const float ASPECT_RATIO{ WINDOW_WIDTH / WINDOW_HEIGHT };
	const float NEAR{ 0.1f };
	const float FAR{ 1000.0f };
	const float FOV{ std::numbers::pi / 2 };
	const float Q{ FAR / (FAR - NEAR) };

	for (std::size_t i {}; i < m_object.polygons.size(); ++i) {
		for (std::size_t c {}; c < 3; ++c) {
			float z{ m_object.polygons.at(i).vertex.at(c).z * Q - NEAR * Q };
			m_object_projected.polygons.at(i).vertex.at(c).x = ASPECT_RATIO * 1 / (FOV / 2) * m_object.polygons.at(i).vertex.at(c).x / z;
			m_object_projected.polygons.at(i).vertex.at(c).y = 1 / (FOV / 2) * m_object.polygons.at(i).vertex.at(c).y / z;
		}
	}
}

void Object::project_object() {
	for (Polygon2d &polygon : m_object_projected. polygons) {
		project_polygon(polygon);
	}
}

void Object::project_polygon(Polygon2d &polygon) {
	for (Vec2d &vertex : polygon.vertex) {
		vertex.x = (1 + vertex.x) * WINDOW_WIDTH / 2;
		vertex.y = (1 + (-1) * vertex.y) * WINDOW_HEIGHT / 2;
	}
}

void Object::render_object(SDL_Renderer *renderer) const {
	for (std::size_t i {}; i < m_object_projected.polygons.size(); ++i) {
		render_polygon(renderer, m_object_projected.polygons.at(i), m_object.polygons.at(i));
	}
}

void Object::render_polygon(SDL_Renderer *renderer, const Polygon2d polygon2d, const Polygon3d polygon3d) const {
	if ((polygon3d.vertex.at(0).z < 0) &&
		(polygon3d.vertex.at(1).z < 0) &&
		(polygon3d.vertex.at(2).z < 0)) { return; }

	if (((polygon2d.vertex.at(0).x < 0) || (polygon2d.vertex.at(0).x > WINDOW_WIDTH) || 
		 (polygon2d.vertex.at(0).y < 0) || (polygon2d.vertex.at(0).y > WINDOW_HEIGHT)) &&
		((polygon2d.vertex.at(1).x < 0) || (polygon2d.vertex.at(1).x > WINDOW_WIDTH) || 
		 (polygon2d.vertex.at(1).y < 0) || (polygon2d.vertex.at(1).y > WINDOW_HEIGHT)) &&
		((polygon2d.vertex.at(2).x < 0) || (polygon2d.vertex.at(2).x > WINDOW_WIDTH) || 
		 (polygon2d.vertex.at(2).y < 0) || (polygon2d.vertex.at(2).y > WINDOW_HEIGHT))) { return; }

	SDL_RenderLine(renderer, polygon2d.vertex.at(0).x, polygon2d.vertex.at(0).y, polygon2d.vertex.at(1).x, polygon2d.vertex.at(1).y);
	SDL_RenderLine(renderer, polygon2d.vertex.at(1).x, polygon2d.vertex.at(1).y, polygon2d.vertex.at(2).x, polygon2d.vertex.at(2).y);
	SDL_RenderLine(renderer, polygon2d.vertex.at(2).x, polygon2d.vertex.at(2).y, polygon2d.vertex.at(0).x, polygon2d.vertex.at(0).y);
}
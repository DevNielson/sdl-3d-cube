#include "object.hpp"

Object::Object(const glm::vec3 position, const utils::Object3d obj)
	: m_position{ position },
	  m_object{ obj },
	  m_object_projected{ std::vector<utils::Polygon2d>{ m_object.polygons.size() } }
{
	translation();
	project_object();
}

void Object::real_coordinates_log() const
{
	std::println("{:*^20}", '*');
	std::println("Coordinates x, y, z");
	std::println("{:*^20}", '*');

	std::println("position x: {}", m_position.x);
	std::println("position y: {}", m_position.y);
	std::println("position z :{}\n", m_position.z);

	std::println("{:*^20}\n", '*');
}

void Object::coordinates_log() const
{
	std::println("{:*^20}", '*');
	std::println("Real Coordinates x, y");
	std::println("{:*^20}", '*');

	for (utils::Polygon2d polygon : m_object_projected.polygons)
	{
		std::println("vertex0 x = {}", polygon.vertex.at(0).x);
		std::println("vertex0 y = {}\n", polygon.vertex.at(0).y);

		std::println("vertex1 x = {}", polygon.vertex.at(1).x);
		std::println("vertex1 y = {}\n", polygon.vertex.at(1).y);

		std::println("vertex2 x = {}", polygon.vertex.at(2).x);
		std::println("vertex2 y = {}", polygon.vertex.at(2).y);
	}
	std::println("{:*^20}\n", '*');
}

void Object::update()
{
	const bool *KEY_STATE{ SDL_GetKeyboardState(nullptr) };
	constexpr float SPEED{ 0.5f };

	if (KEY_STATE[SDL_SCANCODE_W])
	{
		m_position.z += SPEED;

		translation();
		project_object();
	}
	if (KEY_STATE[SDL_SCANCODE_A])
	{
		m_position.x -= SPEED;

		translation();
		project_object();
	}
	if (KEY_STATE[SDL_SCANCODE_S])
	{
		m_position.z -= SPEED;

		translation();
		project_object();
	}
	if (KEY_STATE[SDL_SCANCODE_D])
	{
		m_position.x += SPEED;

		translation();
		project_object();
	}
	if (KEY_STATE[SDL_SCANCODE_SPACE])
	{
		m_position.y += SPEED;

		translation();
		project_object();
	}
	if (KEY_STATE[SDL_SCANCODE_LSHIFT])
	{
		m_position.y -= SPEED;

		translation();
		project_object();
	}
}

void Object::translation()
{
	constexpr float ASPECT_RATIO{ WINDOW_WIDTH / WINDOW_HEIGHT };
	constexpr float NEAR{ 0.1f };
	constexpr float FAR{ 1000.0f };
	constexpr float FOV{ std::numbers::pi / 2 };
	// constexpr float FOV{ 45.0f };
	constexpr float Q{ FAR / (FAR - NEAR) };

    // glm::mat4 proj{ glm::perspective(glm::radians(FOV), ASPECT_RATIO, NEAR, FAR) };

	for (std::size_t i {}; i < m_object.polygons.size(); ++i)
	{
		constexpr std::size_t NUMBER_OF_VERTEX{ 3 };
		for (std::size_t c {}; c < NUMBER_OF_VERTEX; ++c)
		{
			float z{ (m_object.polygons.at(i).vertex.at(c).z + m_position.z) * Q - NEAR * Q };
			m_object_projected.polygons.at(i).vertex.at(c).x = ASPECT_RATIO * 1 / (FOV / 2) * (m_object.polygons.at(i).vertex.at(c).x + m_position.x) / z;
			m_object_projected.polygons.at(i).vertex.at(c).y = 1 / (FOV / 2) * (m_object.polygons.at(i).vertex.at(c).y + m_position.y) / z;
		}
	}
}

void Object::project_object()
{
	for (utils::Polygon2d &polygon : m_object_projected.polygons)
	{
		project_polygon(polygon);
	}
}

void Object::project_polygon(utils::Polygon2d &polygon)
{
	for (glm::vec3 &vertex : polygon.vertex)
	{
		vertex.x = (1 + vertex.x) * WINDOW_WIDTH / 2;
		vertex.y = (1 + (-1) * vertex.y) * WINDOW_HEIGHT / 2;
	}
}

void Object::render_object(SDL_Renderer *renderer) const
{
	for (std::size_t i {}; i < m_object_projected.polygons.size(); ++i)
	{
		render_polygon(renderer, m_object_projected.polygons.at(i), m_object.polygons.at(i));
	}
}

void Object::render_polygon(SDL_Renderer *renderer, const utils::Polygon2d polygon2d, const utils::Polygon3d polygon3d) const
{
	if (m_position.z <= 0.0f) { return; }

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
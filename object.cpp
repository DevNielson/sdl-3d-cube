#include "object.hpp"

Object::Object(Object3d obj3d, Object2d obj2d)
	: m_object { obj3d },
	  m_objectProjected { obj2d }
{
	matrixOfProjection();
	projectObject();

	coordinatesLog();
	realCoordinatesLog();
}

void Object::coordinatesLog()
{
	std::println("{:*^20}", '*');
	std::println("Coordinates x, y, z");
	std::println("{:*^20}", '*');
	for (Polygon3d polygon : m_object.polygons)
	{
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
		std::println();
	}
	std::println("{:*^20}", '*');
	std::println();
}

void Object::realCoordinatesLog()
{
	std::println("{:*^20}", '*');
	std::println("Real Coordinates x, y");
	std::println("{:*^20}", '*');
	for (Polygon2d polygon : m_objectProjected.polygons)
	{
		std::println("vertex0 x = {}", polygon.vertex.at(0).x);
		std::println("vertex0 y = {}", polygon.vertex.at(0).y);
		std::println();

		std::println("vertex1 x = {}", polygon.vertex.at(1).x);
		std::println("vertex1 y = {}", polygon.vertex.at(1).y);
		std::println();

		std::println("vertex2 x = {}", polygon.vertex.at(2).x);
		std::println("vertex2 y = {}", polygon.vertex.at(2).y);
		std::println();
	}
	std::println("{:*^20}", '*');
	std::println();
}

void Object::update()
{
	const bool *keyState { SDL_GetKeyboardState(nullptr) };
	if (keyState[SDL_SCANCODE_W])
	{
		for (Polygon3d &polygon : m_object.polygons)
		{
			for (Vec3d &vertex : polygon.vertex)
			{
				vertex.z += 0.3f;
			}
		}
		matrixOfProjection();
		projectObject();
	}
	if (keyState[SDL_SCANCODE_A])
	{
		for (Polygon3d &polygon : m_object.polygons)
		{
			for (Vec3d &vertex : polygon.vertex)
			{
				vertex.x -= 0.3f;
			}
		}
		matrixOfProjection();
		projectObject();
	}
	if (keyState[SDL_SCANCODE_S])
	{
		for (Polygon3d &polygon : m_object.polygons)
		{
			for (Vec3d &vertex : polygon.vertex)
			{
				vertex.z -= 0.3f;
			}
		}
		matrixOfProjection();
		projectObject();
	}
	if (keyState[SDL_SCANCODE_D])
	{
		for (Polygon3d &polygon : m_object.polygons)
		{
			for (Vec3d &vertex : polygon.vertex)
			{
				vertex.x += 0.3f;
			}
		}
		matrixOfProjection();
		projectObject();
	}
	if (keyState[SDL_SCANCODE_SPACE])
	{
		for (Polygon3d &polygon : m_object.polygons)
		{
			for (Vec3d &vertex : polygon.vertex)
			{
				vertex.y += 0.3f;
			}
		}
		matrixOfProjection();
		projectObject();
	}
	if (keyState[SDL_SCANCODE_LSHIFT])
	{
		for (Polygon3d &polygon : m_object.polygons)
		{
			for (Vec3d &vertex : polygon.vertex)
			{
				vertex.y -= 0.3f;
			}
		}
		matrixOfProjection();
		projectObject();
	}
}

void Object::matrixOfProjection()
{
	float aspectRatio { WINDOW_WIDTH / WINDOW_HEIGHT };
	float near { 0.1f };
	float far { 1000.0f };
	float fov { std::numbers::pi / 2 };
	float q { far / (far - near) };

	for (std::size_t i {}; i < m_object.polygons.size(); ++i)
	{
		for (std::size_t c {}; c < 3; ++c)
		{
			float z { m_object.polygons.at(i).vertex.at(c).z * q - near * q };
			m_objectProjected.polygons.at(i).vertex.at(c).x = aspectRatio * 1 / (fov / 2) * m_object.polygons.at(i).vertex.at(c).x / z;
			m_objectProjected.polygons.at(i).vertex.at(c).y = 1 / (fov / 2) * m_object.polygons.at(i).vertex.at(c).y / z;
		}
	}
}

void Object::projectObject()
{
	for (Polygon2d &polygon : m_objectProjected. polygons)
	{
		projectPolygon(polygon);
	}
}

void Object::projectPolygon(Polygon2d &polygon)
{
	for (Vec2d &vertex : polygon.vertex)
	{
		vertex.x = (1 + vertex.x) * WINDOW_WIDTH / 2;
		vertex.y = (1 + (-1) * vertex.y) * WINDOW_HEIGHT / 2;
	}
}

void Object::renderObject(SDL_Renderer *renderer) const
{
	for (std::size_t i {}; i < m_objectProjected.polygons.size(); ++i)
	{
		renderPolygon(renderer, m_objectProjected.polygons.at(i), m_object.polygons.at(i));
	}
}

void Object::renderPolygon(SDL_Renderer *renderer, Polygon2d polygon2d, Polygon3d polygon3d) const
{
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
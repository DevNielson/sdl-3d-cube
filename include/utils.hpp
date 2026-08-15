#pragma once
#include "main.hpp"

namespace utils
{
    struct Polygon3d { std::array<glm::vec3, 3> vertex{}; };
    struct Object3d { std::vector<Polygon3d> polygons; };

    struct Polygon2d { std::array<glm::vec3, 3> vertex{}; };
    struct Object2d { std::vector<Polygon2d> polygons; };
}
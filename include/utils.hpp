#pragma once
#include "main.hpp"

namespace utils
{
    struct Vec3d { float x{}, y{}, z{}; };
    struct Polygon3d { std::array<Vec3d, 3> vertex{}; };
    struct Object3d { std::vector<Polygon3d> polygons; };

    struct Vec2d { float x{}, y{}; };
    struct Polygon2d { std::array<Vec2d, 3> vertex{}; };
    struct Object2d { std::vector<Polygon2d> polygons; };
}
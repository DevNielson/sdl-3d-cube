#pragma once
#include <array>
#include <format>
#include <numbers>
#include <print>
#include <SDL3/SDL.h>
#include <string>
#include <vector>

struct Vec3d { float x{}, y{}, z{}; };
struct Polygon3d { std::array<Vec3d, 3> vertex{}; };
struct Object3d { std::vector<Polygon3d> polygons; };

struct Vec2d { float x{}, y{}; };
struct Polygon2d { std::array<Vec2d, 3> vertex{}; };
struct Object2d { std::vector<Polygon2d> polygons; };

const std::string WINDOW_TITLE{ "3D GAME" };
constexpr int WINDOW_WIDTH{ 800 };
constexpr int WINDOW_HEIGHT{ 800 };
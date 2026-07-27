#pragma once
#include "main.hpp"

Object3d object
{ {
	// Norte
	Polygon3d
	{
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 0.0f } },
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 0.0f } },
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 0.0f } }
	},
	Polygon3d
	{
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 0.0f } },
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 0.0f } },
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 0.0f } }
	},

	// Sul
	Polygon3d
	{
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 1.0f } },
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 1.0f } },
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 1.0f } }
	},
	Polygon3d
	{
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 1.0f } },
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 1.0f } },
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 1.0f } }
	},

	// Leste
	Polygon3d
	{
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 0.0f } },
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 0.0f } },
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 1.0f } }
	},
	Polygon3d
	{
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 1.0f } },
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 1.0f } },
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 0.0f } }
	},

	// Oeste
	Polygon3d
	{
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 1.0f } },
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 1.0f } },
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 0.0f } }
	},
	Polygon3d
	{
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 0.0f } },
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 0.0f } },
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 1.0f } }
	},

	// Topo
	Polygon3d
	{
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 0.0f } },
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 1.0f } },
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 1.0f } }
	},
	Polygon3d
	{
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 1.0f } },
		Vec3d { .x { 1.0f }, .y { 1.0f }, .z { 0.0f } },
		Vec3d { .x { 0.0f }, .y { 1.0f }, .z { 0.0f } }
	},

	// Baixo
	Polygon3d
	{
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 1.0f } },
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 0.0f } },
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 0.0f } }
	},
	Polygon3d
	{
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 0.0f } },
		Vec3d { .x { 1.0f }, .y { 0.0f }, .z { 1.0f } },
		Vec3d { .x { 0.0f }, .y { 0.0f }, .z { 1.0f } }
	}
} };

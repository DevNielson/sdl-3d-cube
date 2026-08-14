#pragma once
#include "utils.hpp"

utils::Object3d object{ {
	// Norte
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 0.0f } },
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 0.0f } },
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 0.0f } }
	},
		utils::Polygon3d{ utils::Vec3d
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 0.0f } },
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 0.0f } },
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 0.0f } }
	},

	// Sul
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 1.0f } },
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 1.0f } },
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 1.0f } }
	},
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 1.0f } },
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 1.0f } },
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 1.0f } }
	},

	// Leste
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 0.0f } },
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 0.0f } },
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 1.0f } }
	},
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 1.0f } },
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 1.0f } },
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 0.0f } }
	},

	// Oeste
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 1.0f } },
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 1.0f } },
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 0.0f } }
	},
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 0.0f } },
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 0.0f } },
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 1.0f } }
	},

	// Topo
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 0.0f } },
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 1.0f } },
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 1.0f } }
	},
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 1.0f } },
		{ .x{ 1.0f }, .y{ 1.0f }, .z{ 0.0f } },
		{ .x{ 0.0f }, .y{ 1.0f }, .z{ 0.0f } }
	},

	// Baixo
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 1.0f } },
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 0.0f } },
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 0.0f } }
	},
	utils::Polygon3d{ utils::Vec3d
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 0.0f } },
		{ .x{ 1.0f }, .y{ 0.0f }, .z{ 1.0f } },
		{ .x{ 0.0f }, .y{ 0.0f }, .z{ 1.0f } }
	}
} };

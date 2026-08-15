#pragma once
#include "utils.hpp"

utils::Object3d object{ {
	// Norte
	utils::Polygon3d{ glm::vec3
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f },
		{ 1.0f, 1.0f, 0.0f }
	},
		utils::Polygon3d{ glm::vec3
		{ 1.0f, 1.0f, 0.0f },
		{ 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f }
	},

	// Sul
	utils::Polygon3d{ glm::vec3
		{ 1.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 1.0f }
	},
	utils::Polygon3d{ glm::vec3
		{ 0.0f, 1.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f }
	},

	// Leste
	utils::Polygon3d{ glm::vec3
		{ 1.0f, 0.0f, 0.0f },
		{ 1.0f, 1.0f, 0.0f },
		{ 1.0f, 1.0f, 1.0f }
	},
	utils::Polygon3d{ glm::vec3
		{ 1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f }
	},

	// Oeste
	utils::Polygon3d{ glm::vec3
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 0.0f }
	},
	utils::Polygon3d{ glm::vec3
		{ 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f }
	},

	// Topo
	utils::Polygon3d{ glm::vec3
		{ 0.0f, 1.0f, 0.0f },
		{ 0.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f }
	},
	utils::Polygon3d{ glm::vec3
		{ 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f }
	},

	// Baixo
	utils::Polygon3d{ glm::vec3
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 0.0f }
	},
	utils::Polygon3d{ glm::vec3
		{ 1.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f }
	}
} };

#pragma once

namespace btk {
	class Category {
		public:
			std::shared_ptr<Category> parent;
			std::vector<std::shared_ptr<Category>> subcategories;
	};
};

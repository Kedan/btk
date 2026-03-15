#include <exception>
#include <collection.hpp>

namespace btk {	
	Collection::Collection(const std::string& t_filepath) {
		load(t_filepath);
	}

	bool Collection::load(const std::string& t_filepath) {
		filepath = t_filepath;
		try {
			// load file
			return true;
		} catch(const std::exception& e) {
			std::cerr << "Collection load: " << e.what() << "\n";
		}
		return false;
	}

	bool Collection::loadGcStarCollection(const std::string& t_filepath) {
		return false;
	}

	int Collection::add(const Book& book) {
		return 0;
	}	
}; // namespace btk

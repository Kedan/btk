#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <vector>

#include <book.hpp>

namespace btk {
	
	class Collection {
		protected:
			std::string name;
			std::string filepath;

			std::vector<std::shared_ptr<Book>> books;

			std::vector<std::shared_ptr<Book>> favourites;
			std::vector<std::shared_ptr<Book>> important;
			std::vector<std::shared_ptr<Book>> borrowed;
			std::vector<std::shared_ptr<Book>> readed;

			std::vector<std::shared_ptr<Category>> categories;
			std::vector<std::shared_ptr<Person>> persons;
			std::vector<std::shared_ptr<Publisher>> publishers;
			std::vector<std::shared_ptr<Localization>> localizations;

		public:
			Collection() = default;
			Collection(const std::string& t_filepath);
			~Collection() = default;
			Collection(const Collection&) = delete;

			int add(const Book& book);
			bool load(const std::string& t_filepath);
			bool loadGcStarCollection(const std::string& filepath);
	};

}; // namespace btk

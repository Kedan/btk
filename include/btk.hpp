#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <vector>

namespace btk {
	
	struct ReadingState {
		static constexpr unsigned int NOT_READED{0x0};
		static constexpr unsigned int READING{0x00000001};
		static constexpr unsigned int READED{0x0000010};
		static constexpr unsigned int PAUSED{0x00000100};
	};

	class Person {
		public:
			std::string name;
			std::string firstname;
	};

	class Publisher {
		public:
			std::string fullname;
			std::string name;
	};

	class Localization {
		public:
			std::string name;
	};
	
	class Source {
		public:
			std::string name;
	};
	
	class Category {
		public:
			std::shared_ptr<Category> parent;
			std::vector<std::shared_ptr<Category>> subcategories;
	};
	
	struct BookFlags {
		static constexpr unsigned int IMPORTANT		{0x00000001};	
		static constexpr unsigned int FAVOURITE		{0x00000010};
		static constexpr unsigned int BORROWED		{0x00000100};
		static constexpr unsigned int READED			{0x00001000};
		static constexpr unsigned int READING			{0x00010000};
		static constexpr unsigned int CYCLE_COMPLETE	{0x00100000};
		static constexpr unsigned int MULTIPLE		{0x01000000};	
	};
	
	class EAN {
		public:
			int code;
	};

	class ISBN {
		public:
			std::string code;
	};

	class Book {
		protected:
			std::chrono::year publicationDate;
			std::chrono::year_month_day aquisitionDate;
			std::vector<std::shared_ptr<Person>> authors;
			std::vector<std::shared_ptr<Person>> mainAuthor;
			std::vector<std::shared_ptr<Person>> translator;
			std::vector<std::shared_ptr<Person>> borrowHistory;
			std::vector<std::shared_ptr<Category>> categories;
			std::shared_ptr<Publisher> publisher;
			std::shared_ptr<Source> source;
			std::shared_ptr<Localization> localization;
			std::string title;
			std::string lang;
			std::string comment;
			float price;
			int cycle{0};
			unsigned int state;
			unsigned int pages;
			unsigned int cover;
			unsigned int edition;
			unsigned int review;
			unsigned char read;
			unsigned short int flags;
			EAN ean;
			ISBN isbn;
		public:
			Book( const std::string& t_title
					, int yearOfPublication
					, std::vector<std::string> t_authors
					, unsigned int t_pages
					, unsigned int t_cover
					, int yyyy
					, unsigned int mm
					, unsigned int dd
					, float t_price
			   		, unsigned short int t_flags ) 
				: title{t_title}
				, publicationDate{yearOfPublication}
				, pages{t_pages}
				, aquisitionDate{std::chrono::year{yyyy}, std::chrono::month{mm}, std::chrono::day{dd}}
				, price{t_price}
				, flags{t_flags} {

				}
			inline void setAs(const unsigned short int f) { flags|=f; }
			inline bool is(const unsigned short int f) { return flags & f; }
	};

	class btk {
		protected:
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
			btk() = default;
			~btk() = default;
			btk(const btk&) = delete;

			int add(const Book& book) {
				return 0;
			}

			bool loadGcStarCollection(const char* filepath){
				return true;
			}
	};

}; // namespace btk

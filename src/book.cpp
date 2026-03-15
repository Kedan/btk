#include <book.hpp>

namespace btk {
	Book::Book( const std::string& t_title
		, int yearOfPublication
		, std::vector<std::string> t_authors
		, unsigned int t_pages
		, unsigned int t_cover
		, int yyyy
		, unsigned int mm
		, unsigned int dd
		, float t_price
		, unsigned short int t_flags
	   	, int t_cycle ) 
		: title{t_title}
		, publicationDate{yearOfPublication}
		, pages{t_pages}
		, aquisitionDate{std::chrono::year{yyyy}, std::chrono::month{mm}, std::chrono::day{dd}}
		, price{t_price}
		, flags{t_flags}
	       	, cycle{t_cycle}	{
			//constructor body
	}

}; // namespace btk

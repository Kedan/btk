#pragma once

#include <nudny/util/cli_parser.hpp>
#include <collection.hpp>

namespace btk {
	class Biblioteka {
		protected:
			nudny::util::CliParser parser;
			std::vector<std::shared_ptr<Collection>> collection;

			void handleEvent();
		public:
			Biblioteka() = default;
			Biblioteka(const Biblioteka&) = delete;
			Biblioteka(int t_argc, char* t_argv[]);
			~Biblioteka() = default;
	};

	int btk(int t_argc, char* t_argv[]);
}; 

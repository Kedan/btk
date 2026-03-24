#pragma once

#include <unordered_map>
#include <functional>

#include <nudny/util/cli_parser.hpp>
#include <collection.hpp>

namespace btk {
	class Biblioteka {
		public:
			Biblioteka() = default;
			Biblioteka(const Biblioteka&) = delete;
			Biblioteka(int t_argc, char* t_argv[]);
			~Biblioteka() = default;
		protected:

			std::string defaultCollctionDir{"~/.btk/collections/"};
			std::shared_ptr<nudny::util::CliParser> parser;
			nudny::util::Commander cmd;
			std::vector<std::shared_ptr<Collection>> collection;
			
			
			void handleEvent();
			void loadDir(const std::string& t_dirPath);

			void add();
			void findBook();
			
		private:
			std::unordered_map<std::string, std::function<void()>> actions{
				{"add", [this](){ add();} },
			};

	};

	int btk(int t_argc, char* t_argv[]);
}; 

#include <iostream>
#include <filesystem>

#include <btk.hpp>

namespace btk {
	Biblioteka::Biblioteka(int t_argc, char* t_argv[]) 
		: parser{std::make_shared<nudny::util::CliParser>(t_argc, t_argv)}	{
			cmd.setCli(parser);
			handleEvent();
		}

	void Biblioteka::handleEvent() {
		if(auto it = actions.find(cmd.cli(0)); it != actions.end()) {
				it->second();
		} else {
			std::cout << "Unknown command\n";
		}	
	}	

	void Biblioteka::loadDir(const std::string& t_dirPath) {
		/*
		 * if(dir not empty) {
		 * 	for(each file in dir) {
		 * 		if(file is collection) {
		 * 			shared<Col> c = make_shar;
		 * 			if(c->load(file)) {
		 * 				collections.push_back(c)
		 * 				cout "collection <name> loaded"
		 * 				return 0;
		 * 			} else {
		 * 				cout "could not load <name> collection;
		 * 				return 2;
		 * 			}
		 * 		}
		 * 	}
		 * }
		 * cout "dir empty"
		 * return 1;
		 */
	}
	
	void Biblioteka::add() {
		std::cout << "Add book\n";
	}

	int btk(int t_argc, char* t_argv[]) {
		Biblioteka b(t_argc, t_argv);
		return 0;
	}
}; // namespace btk

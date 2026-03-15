#include <btk.hpp>

namespace btk {
	Biblioteka::Biblioteka(int t_argc, char* t_argv[])
		: parser{t_argc, t_argv} {
			handleEvent();
		}

	void Biblioteka::handleEvent() {
		if(parser.exist("l")) {
			std::cout << "Loading collection " << parser.get("l") << "\n";
			//collection.push_back(std::make_shared<Collection>(parser.get("load")));
		}
	}	
	
	int btk(int t_argc, char* t_argv[]) {
		Biblioteka b(t_argc, t_argv);
		return 0;
	}
}; // namespace btk

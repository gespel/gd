#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>

class GDMain {
	public:
		GDMain();
		void initialize();
		void commandloop();
		void parse_command_input(std::string userinput);
		void create_interactive_container(std::string os_name, std::string container_name);
	private:


};

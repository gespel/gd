#include "gd.h"

GDMain::GDMain() {
	this->initialize();
	this->commandloop();

}

void GDMain::initialize() {
	std::cout << "Gouod Docker management is initializing..." << std::endl;


}
void GDMain::commandloop() {
	while(1) {
		std::string userinput;
		std::cout << "gd> ";
		std::cin >> userinput;
		this->parse_command_input(userinput);
	}

}
void GDMain::parse_command_input(std::string userinput) {
	if(userinput == "credits") {
		std::cout << "This tool was written by Sten (Gespel) Heimbrodt." << std::endl 
			<< "It is licensed under the GPLv3." << std::endl; 
	} 
	else if(userinput == "interactive") {
		std::string os;
		std::string name;
		std::cin >> os;
		std::cin >> name;
		this->create_interactive_container(os, name);
	}
	else if(userinput == "exit") {
		exit(0);
	}
	else {
		std::cout << "Unknown command!" << std::endl;
	}
}
void GDMain::create_interactive_container(std::string os_name, std::string container_name) {
	std::string createFolder = "mkdir " + container_name;
	system(createFolder.c_str());
	std::string filepath = container_name + "/Dockerfile";
	std::ofstream file;
   	file.open(filepath);

	file << "FROM " << os_name << std::endl
		//<< "RUN apt-get update && apt-get upgrade && \\" << std::endl
		//<< "apt-get install -y ca-certificates build-essential" << std::endl
		<< "RUN mkdir /" << container_name << std::endl
		<< "WORKDIR /" << container_name << std::endl;

	file.close();
	std::string pull = "docker pull " + os_name;
	system(pull.c_str());
	std::string cmd = "sudo docker build -t " + os_name + " " + container_name;
	system(cmd.c_str());
	cmd = "sudo docker run -it " + os_name;
	system(cmd.c_str());
}
int main() {
	GDMain *gd = new GDMain();
	return 0;
}

#include <iostream>
#include "Symbol_table.h"
#include <fstream>
#include "python_to_c_function.h"
#include <string> 
#include <algorithm>
#include "helper.h"
int main() {
	std::ifstream file;
	file.open("test.py");
	std::string file_content;
	Symbol_table table;
	int line = 0;
	while (std::getline(file, file_content))
	{
		line++;
		//checking if there is assigning to variable
		int pos = file_content.find("=");
		if (pos != std::string::npos) {
			std::string name = "";
			bool invalid = checkName(name, pos, file_content);
			//if name is valid check type and scope
			if (invalid == false && name.size() > 0) {
				std::string type = checkType(file_content.substr(pos + 1));
				std::string scope;
				if (file_content.rfind(name, 0) == 0)
					scope = "global";
				else
				{
					std::map<std::vector<int>, std::string> functions = table.getFunctions();
				}
			}
		}
	}
	file.close();
	return 0;
}
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
	bool error = false;
	//symbol table
	while (std::getline(file, file_content))
	{
		line++;
		std::vector<int> lines;
		//checking if there is assigning to variable
		int pos = file_content.find("=");
		if (pos != std::string::npos) {
			std::string name = "";
			bool invalid = checkName(name, pos, file_content);
			//if name is valid check type and scope
			if (invalid == false && name.size() > 0) {
				std::string type = checkType(file_content.substr(pos + 1));
				std::string scope = checkScope(line, name, file_content, table);
				lines.push_back(line);
				std::vector<std::string> types;
				types.push_back(type);
				table.insert(name, Symbol_table_entre(types, scope, lines));
			}
			else
			{
				error = true;
				break;
			}
		}
		else if ((pos = file_content.find('(')) != std::string::npos)
		{
			std::string name = "";
			bool invalid = checkName(name, pos, file_content);
			if (invalid == false && name.size() > 0) {
				std::string scope = checkScope(line, name, file_content, table);
				lines.push_back(line);
				std::vector<std::string> types;
				types.push_back("function");
				table.insert(name, Symbol_table_entre(types, scope, lines));
			}
			else
			{
				error = true;
				break;
			}
		}
	}
	if (error)
		std::cerr << "symbol table error";
	//rewind to the start of the file
	file.clear();
	file.seekg(0);


	//syntax analyzer

	file.close();
	return 0;
}
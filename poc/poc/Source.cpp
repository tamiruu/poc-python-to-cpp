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
	while (std::getline(file, file_content))
	{
		//checking if there is assigning to variable
		int pos = file_content.find("=");
		if (pos != std::string::npos) {
			//check variable name
			std::string name = "";
			bool invalid = checkName(name, pos, file_content);
			//if name is valid check type
			if (invalid == false && name.size() > 0) {
				std::string type;
				std::string value = file_content.substr(pos + 1);
				//string
				if (std::count(value.begin(), value.end(), '"') >= 2 && std::count(value.begin(), value.end(), '\'') >= 2)
					type = "string";
				//numbers
				int found = value.find_first_not_of("0123456789. \t");
				if (found == std::string::npos)
				{
					std::string temp = "";
					for (int i = 0; i < value.size(); i++)
					{
						if (value[i] == ' ' || value[i] == '\t')
						{
							if (temp.size() == 0)
								continue;
							for (; i < pos; i++)
							{
								if (!(value[i] == ' ' || value[i] == '\t')) {
									invalid = true;
									break;
								}
							}
							if (invalid)
								break;
						}
						else
							temp += value[i];
					}
					if (invalid)
						type = "error";
					//float or int
					if (std::count(temp.begin(), temp.end(), '.') >= 1)
					{
						if (std::count(temp.begin(), temp.end(), '.') > 1)
							type = "error";
						else if (temp.find(".") + 1 == temp.size())
							type = "error";
						else
							type = "float";
					}
					else
						type = "int";
				}
			}
		}
	}
	file.close();
	return 0;
}
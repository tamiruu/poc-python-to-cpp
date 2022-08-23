#include <iostream>
#include <fstream>
#include <string> 
#include <algorithm>
#include "Symbol_table.h"
#include "python_to_c_function.h"
#include "helper.h"
#include "lexical_analzer.h"
#include "syntax analyzer.h"
#include "advanced_code_maker.h"
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
				types.push_back("variable");
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
	//lexical_analzer
	std::vector <std::string> code;
	std::string str;
	while (std::getline(file, str))
	{
		if (str.size() > 0)
			code.push_back(str);
	}
	std::vector<token> tokens = tokenizer(code, table);
	//syntax analyzer
	syntax_tree_node* head = syntax_tree_node::create_syntax_tree(tokens);
	//advanced code maker
	advanced_code_maker(head, table);
	file.close();
	return 0;
}
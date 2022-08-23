#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
class Symbol_table_entre {
public:
	Symbol_table_entre(std::vector<std::string>& type, std::string& _scope, std::vector<int> line);
	std::vector<int> get_lines();
	std::string getScope();
	bool isFunction();
	std::vector<std::string> getType();
private:
	std::vector<std::string> _type;
	std::string _scope;
	std::vector<int> _lines;
};

class Symbol_table {
public:
	void insert(std::string name, Symbol_table_entre entre);
	Symbol_table_entre getEntre(std::string name);
	std::map<std::vector<int>, std::string> getFunctions();
private:
	std::map<std::string, Symbol_table_entre> _entries;
};

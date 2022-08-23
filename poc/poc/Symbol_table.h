#pragma once
#include <iostream>
#include <map>
#include <vector>
class Symbol_table_entre {
public:
	Symbol_table_entre(std::vector<std::string>& type, std::string& _scope, int line);
private:
	std::vector<std::string> _type;
	std::string _scope;
	int _line;
};

class Symbol_table {
public:
	Symbol_table(std::map<std::string, Symbol_table_entre>& entries);
private:
	std::map<std::string, Symbol_table_entre> _entries;
};

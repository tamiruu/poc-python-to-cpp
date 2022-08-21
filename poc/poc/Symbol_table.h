#pragma once
#include <iostream>
#include <map>
#include <vector>
class Symbol_table_entre {
private:
	std::vector<std::string> type;
	std::string scope;
	int line;
};

class Symbol_table {
private:
	std::map<std::string, Symbol_table_entre> entries;
};
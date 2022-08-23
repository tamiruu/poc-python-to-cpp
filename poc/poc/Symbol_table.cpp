#include "Symbol_table.h"

Symbol_table_entre::Symbol_table_entre(std::vector<std::string>& type, std::string& scope, int line)
{
	_type = type;
	_scope = scope;
	_line = line;
}

Symbol_table::Symbol_table(std::map<std::string, Symbol_table_entre>& entries)
{
	entries = _entries;
}

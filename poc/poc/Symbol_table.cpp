#include "Symbol_table.h"

Symbol_table_entre::Symbol_table_entre(std::vector<std::string>& type, std::string& scope, std::vector<int> line)
{
	_type = type;
	_scope = scope;
	_line = line;
}

std::vector<int> Symbol_table_entre::get_line()
{
	return _line;
}

std::string Symbol_table_entre::getScope()
{
	return _scope;
}

bool Symbol_table_entre::isFunction()
{
	if (std::find(_type.begin(), _type.end(), "function") != _type.end())
		return true;
	return false;
}

std::vector<std::string> Symbol_table_entre::getType()
{
	return _type;
}

void Symbol_table::insert(std::string name, Symbol_table_entre entre)
{
	_entries[name] = entre;
}

Symbol_table_entre Symbol_table::getEntre(std::string name)
{
	return _entries[name];
}

std::map<std::vector<int>, std::string> Symbol_table::getFunctions()
{
	std::map<std::vector<int>, std::string> functions;
	for (std::map<std::string, Symbol_table_entre>::iterator it = _entries.begin(); it != _entries.end(); ++it)
	{
		if (it->second.isFunction())
		{
			functions[it->second.get_line()] = it->first;
		}
	}
	return functions;
}

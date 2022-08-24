#include "Symbol_table.h"

Symbol_table_entre::Symbol_table_entre(std::vector<std::string>& type, std::string& scope, std::vector<int> line)
{
	_type = type;
	_scope = scope;
	_lines = line;
}

std::vector<int> Symbol_table_entre::get_lines()
{
	return _lines;
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

bool Symbol_table_entre::isVariable()
{
	if (std::find(_type.begin(), _type.end(), "variable") != _type.end())
		return true;
	return false;
}

std::vector<std::string> Symbol_table_entre::getType()
{
	return _type;
}

bool Symbol_table_entre::operator<(const Symbol_table_entre& other) const
{
	return _lines[0] <= other._lines[0];
}

void Symbol_table::insert(std::string name, Symbol_table_entre entre)
{
	_entries.insert(std::make_pair(name,entre));
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
			functions[it->second.get_lines()] = it->first;
		}
	}
	return functions;
}

bool Symbol_table::isExist(std::string name)
{
	if (_entries.find(name) == _entries.end())
		return false;
	return true;
}

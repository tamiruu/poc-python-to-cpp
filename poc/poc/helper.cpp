#include "helper.h"

bool checkName(std::string& name, int pos, const std::string& file_content)
{
	bool invalid = false;
	for (int i = 0; i < pos; i++)
	{
		if (file_content[i] == ' ' || file_content[i] == '\t')
		{
			if (name.size() == 0)
				continue;
			for (; i < pos; i++)
			{
				if (!(file_content[i] == ' ' || file_content[i] == '\t')) {
					invalid = true;
					break;
				}
			}
			if (invalid)
				break;
		}
		if ((file_content[i] >= 'a' && file_content[i] <= 'z') || (file_content[i] >= 'A' && file_content[i] <= 'Z') || file_content[i] == '_')
			name += file_content[i];
		if (file_content[i] >= '0' && file_content[i] <= '9' && name.size() > 0)
			name += file_content[i];
	}
	return invalid;
}

std::string checkType(std::string value)
{
	std::string type;
	bool invalid = false;
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
				for (; i < value.size(); i++)
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
	return type;
}
bool is_keywords(std::string word) {
	std::string keywords[36] = { "False", "await", "else", "import", "pass", "None", "break", "except", "in", "raise", "True", "class", "finally", "is", "return", "try", "and", "continue", "for", "lambda", "try", "as", "def", "from", "nonlocal", "while", "assert", "del", "global", "not", "with", "async", "elif", "if", "or", "yield" };
	if (std::find(std::begin(keywords), std::end(keywords), word) != std::end(keywords))
	{
		return true;
	}
	return false;
}
bool is_operator(std::string word) {
	std::string operators[31] = {"+", "-", "*", "/", "//", "%", "**", "=", "<", "==", "!=", ">=", "<=", "&", "|", "~", "^", ">>", "<<", "+=", "-=", "*=", "/=", "%=", "//=", "**=", "&=", "|=", "^=", ">>=", "<<=" };
	if (std::find(std::begin(operators), std::end(operators), word) != std::end(operators))
	{
		return true;
	}
	return false;
}

bool is_punctuation(std::string word) {
	std::string punctuations[3] = { "(", ")", "\n" };
	if (std::find(std::begin(punctuations), std::end(punctuations), word) != std::end(punctuations))
	{
		return true;
	}
	return false;
}
std::string checkScope(int line, const std::string& name, const std::string& file_content, Symbol_table& table)
{
	std::string scope;
	if (file_content.rfind(name, 0) == 0)
		scope = "global";
	else
	{
		std::map<std::vector<int>, std::string> functions = table.getFunctions();
		for (auto i : functions)
		{
			if (i.first[0] < line && i.first[1] >= line)
				scope = i.second;
		}
	}
	return scope;
}
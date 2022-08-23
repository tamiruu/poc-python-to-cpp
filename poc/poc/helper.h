#pragma once
#include <iostream>

bool checkName(std::string& name, int pos, const std::string& file_content);//function to check name of variable/function

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
}
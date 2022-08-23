#include "python_to_c_function.h"

std::string python_to_c_function_printf(std::vector<token> function, Symbol_table& table) {
	std::string res = "printf(\"%";
	if (function.size() - 3 == 3)
	{
		if (function[2].get_type() == "identifier" && function[4].get_type() == "identifier" && table.getEntre(function[2].get_token_value()).getType()[0] == table.getEntre(function[4].get_token_value()).getType()[0])
		{
			std::string str = table.getEntre(function[2].get_token_value()).getType()[0];
			if (str == "int")
			{
				res += "d\"";
			}
			else if (str == "float")
			{
				res += "f\"";
			}
			res += function[2].get_token_value() + function[3].get_token_value() + function[4].get_token_value();
		}
	}
	else {
		if (function[2].get_type() == "identifier")
		{
			std::string str = table.getEntre(function[2].get_token_value()).getType()[0];
			if (str == "int")
			{
				res += "d\"";
			}
			else if (str == "float")
			{
				res += "f\"";
			}
			res += function[2].get_token_value();
		}
	}
	res += ");";
	return res;
}
#include "target_code_generator.h"

bool isFunctionExist(std::string& name, Symbol_table& table)
{
	std::vector<std::string> supported_functions{ "printf" };
	if (std::find(supported_functions.begin(), supported_functions.end(), name) != supported_functions.end())
		return true;
	return false;
}

void tree_to_lines(syntax_tree_node* tree, Symbol_table& table, std::ofstream& file)
{
	if (tree != nullptr)
	{
		tree_to_lines(tree->get_left(), table, file);
		std::string value = tree->get_token().get_token_value();
		std::string name;
		if (value.find('(') != std::string::npos)
			(void)checkName(name, value.find('('), value);
		else
			name = value;
		if (table.isExist(name))
		{
			std::vector<std::string> types = table.getEntre(value).getType();
			if (types[1] == "variable")
			{
				if (types[0] == "int")
					file << "\tint " << value;
				else if (types[0] == "float")
					file << "\tfloat " << value;
			}
		}
		else if (isFunctionExist(name, table))
			file << "\t" << value;
		else
			file << value;
		tree_to_lines(tree->get_right(), table, file);
	}
}

void generate_c_file(syntax_tree_node* tree, Symbol_table& table)
{
	std::ofstream file;
	file.open("test.c");
	file << "#include <stdio.h>\n\nint main()\n{\n";
	tree_to_lines(tree, table, file);
	file << "\treturn 0;\n}";
}

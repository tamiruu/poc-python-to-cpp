#include "syntax analyzer.h"

syntax_tree_node::syntax_tree_node(token tok)
{
	_token = tok;
	_left = nullptr;
	_right = nullptr;
}

syntax_tree_node::syntax_tree_node(token tok, syntax_tree_node* left, syntax_tree_node* right)
{
	_token = tok;
	_left = left;
	_right = right;
}

token syntax_tree_node::get_token()
{
	return _token;
}

syntax_tree_node* syntax_tree_node::get_left()
{
	return _left;
}

syntax_tree_node* syntax_tree_node::get_right()
{
	return _right;
}

void syntax_tree_node::set_left(syntax_tree_node* left)
{
	_left = left;
}

void syntax_tree_node::set_right(syntax_tree_node* right)
{
	_right = right;
}

syntax_tree_node* syntax_tree_node::create_syntax_tree(std::vector<token>& tokens)
{
	bool error = false;
	syntax_tree_node* head = nullptr;
	syntax_tree_node* temp = nullptr;
	syntax_tree_node* temp_var = nullptr;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i].get_type() == "function")
		{
			if (head == nullptr)
				head = new syntax_tree_node(tokens[i]);
			else if(tokens[i + 1].get_type()=="operator")
				temp_var = new syntax_tree_node(tokens[i]);
			else 
			{
				temp = head;
				while (temp->_right != nullptr)
					temp = temp->_right;
				temp->set_right(new syntax_tree_node(tokens[i]));
			}
		}
		else if (tokens[i].get_type() == "identifier")
		{
			if (head == nullptr)
				head = new syntax_tree_node(tokens[i]);
			else if (tokens[i + 1].get_token_value() == "\n")
			{
				temp = head;
				while (temp->_right != nullptr)
					temp = temp->_right;
				temp->set_right(new syntax_tree_node(tokens[i]));
			}
			else if (temp_var != nullptr && temp_var->_token.get_token_value() == "(")
			{
				temp = head;
				while (temp->_right != nullptr)
					temp = temp->_right;
				if (tokens[i + 1].get_token_value() == ")")
				{
					temp->set_right(new syntax_tree_node(tokens[i], temp_var, nullptr));
				temp_var = nullptr;
				}
				else
					temp_var = new syntax_tree_node(tokens[i], temp_var, nullptr);
			}
			else if (tokens[i + 1].get_token_value() == ")")
			{
				temp = head;
				while (temp->_right != nullptr)
					temp = temp->_right;
				temp->set_right(new syntax_tree_node(tokens[i]));
			}
			else
				temp_var = new syntax_tree_node(tokens[i]);
		}
		else if (tokens[i].get_type() == "operator")
		{
			if (head == nullptr)
			{
				error = true;
				break;
			}
			else if (head->get_token().get_type() == "identifier")
				head = new syntax_tree_node(tokens[i], head, nullptr);
			else
			{
				temp = head;
				while (temp->get_right() != nullptr)
					temp = temp->get_right();
				if (temp_var == nullptr)
				{
					error = true;
					break;
				}
				temp->set_right(new syntax_tree_node(tokens[i], temp_var, nullptr));
				temp_var = nullptr;
			}
		}
		else if (tokens[i].get_type() == "constant")
		{
			if (tokens[i + 1].get_token_value() == "\n")
			{
				temp = head;
				while (temp->_right != nullptr)
					temp = temp->_right;
				temp->set_right(new syntax_tree_node(tokens[i]));
			}
			else
				temp_var = new syntax_tree_node(tokens[i]);
		}
		else if (tokens[i].get_type() == "punctuation")
		{
			if (head != nullptr)
			{
				if (tokens[i].get_token_value() == "\n") {
					temp = head;
					while (temp->_right != nullptr)
						temp = temp->_right;
					temp->set_right(new syntax_tree_node(tokens[i]));
				}
				else if (tokens[i].get_token_value() == "(")
					temp_var = new syntax_tree_node(tokens[i]);
				else if (tokens[i].get_token_value() == ")")
				{
					temp = head;
					while (temp->_right != nullptr)
						temp = temp->_right;
					temp->set_right(new syntax_tree_node(tokens[i]));
				}
			}
			else
			{
				error = true;
				break;
			}
		}
	}
	return head;
}

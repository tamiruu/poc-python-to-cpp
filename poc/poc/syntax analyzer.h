#pragma once
#include "lexical_analzer.h"

class syntax_tree_node
{
public:
	syntax_tree_node(token);
	syntax_tree_node(token, syntax_tree_node*, syntax_tree_node*);
	token get_token();
	syntax_tree_node* get_left();
	syntax_tree_node* get_right();
	void set_left(syntax_tree_node* left);
	void set_right(syntax_tree_node* right);
	static syntax_tree_node* create_syntax_tree(std::vector<token>& tokens);
private:
	syntax_tree_node* _left;
	syntax_tree_node* _right;
	token _token;
};
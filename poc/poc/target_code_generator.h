#pragma once
#include "syntax analyzer.h"
#include "lexical_analzer.h"
#include "Symbol_table.h"
#include <iostream>
#include <fstream>
#include <vector>
bool isFunctionExist(std::string& name, Symbol_table& table);
void tree_to_lines(syntax_tree_node* tree, Symbol_table& table, std::ofstream& file);
void generate_c_file(syntax_tree_node* tree, Symbol_table& table);
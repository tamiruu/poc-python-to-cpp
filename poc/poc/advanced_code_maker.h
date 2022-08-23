#pragma once
#include "helper.h"
#include "python_to_c_function.h"
#include "syntax analyzer.h"
#include "lexical_analzer.h"

void advanced_code_maker(syntax_tree_node* tree, Symbol_table table);
void tree_to_tokens(syntax_tree_node* tree, std::vector<token>& tokens);
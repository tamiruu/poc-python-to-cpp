#include "advanced_code_maker.h"

void advanced_code_maker(syntax_tree_node* tree, Symbol_table table)
{
    if (tree != nullptr)
    {
        advanced_code_maker(tree->get_left(), table);
        if (tree->get_token().get_type() == "function") {
            std::vector<token> tokens;
            tree_to_tokens(tree, tokens);
            std::string res = python_to_c_function_printf(tokens, table);
            token tok = token(res, "function");
            syntax_tree_node* temp = tree;
            while (temp->get_token().get_token_value() != ")")
            {
                temp = temp->get_right();
            }
            tree->set_right(temp);
            tree->set_token(tok);
        }
        else if (tree->get_token().get_token_value() == "\n")
        {
            tree->set_token(token(";\n","punctuation"));
        }
        advanced_code_maker(tree->get_right(), table);
    }
}

void tree_to_tokens(syntax_tree_node* tree, std::vector<token>& tokens)
{
    if (tree != nullptr && tree->get_token().get_token_value() != "\n")
    {
        tree_to_tokens(tree->get_left(), tokens);
        tokens.push_back(tree->get_token());
        tree_to_tokens(tree->get_right(), tokens);
    }
}

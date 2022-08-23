#include "lexical_analzer.h"

std::vector<std::string> clean_tab_and_space(std::vector<std::string>& code) {
    std::vector<std::string> words;
    for (int i = 0; i < code.size(); i++)
    {
        std::string content = "";
        for (int j = 0; j < code[i].size(); j++)
        {
            if (code[i][j] != ' ' && code[i][j] != '\t' && code[i][j] != '\n')
            {
                if (code[i][j] == '(' || code[i][j] == ')')
                {
                    if (content != "")
                    {
                        words.push_back(content);
                    }
                    content = code[i][j];
                    words.push_back(content);
                    content = "";
                }
                else {
                    content += code[i][j];
                }
            }
            else
            {
                if (content != "")
                {
                    words.push_back(content);
                    content = "";
                }
                if (code[i][j] == '\n')
                {
                    words.push_back("\n");
                }
            }
        }
    }
    return words;
}

void clean_comments(std::vector<std::string>& code) {
    for (int i = 0; i < code.size(); i++)
    {
        std::string content = "";
        for (int j = 0; j < code[i].size(); j++)
        {
            if (code[i][j] != '#' )
            {
                content += code[i][j];
            }
            else {
                break;
            }
        }
        content += "\n";
        code[i] = content;
    }
} 

token::token(std::string value, std::string type) {
    this->token_value = value;
    this->type = type;
}

std::string token::get_token_value()
{
    return this->token_value;
}

std::string token::get_type()
{
    return this->type;
}

std::vector<token> tokenizer(std::vector<std::string>& code, Symbol_table table) {
    std::vector<token> tokens;
    std::vector<std::string> words;
    clean_comments(code);
    words = clean_tab_and_space(code);
    for (std::vector<std::string>::iterator i = words.begin(); i != words.end(); ++i)
    {
        if (is_keywords(*i))
        {
            token tok(*i, "keyword");
            tokens.push_back(tok);
        }
        else if (is_operator(*i))
        {
            token tok(*i, "operator");
            tokens.push_back(tok);
        }
        else if (table.getEntre(*i).isVariable()) 
        {
            token tok(*i, "identifier");
            tokens.push_back(tok);
        }
        else if (checkType(*i) == "int" || checkType(*i) == "float" || checkType(*i) == "str")
        {
            token tok(*i, "constant");
            tokens.push_back(tok);
        }
        else if (table.getEntre(*i).isFunction())
        {
            token tok(*i, "function");
            tokens.push_back(tok);
        }
        else if (is_punctuation(*i))
        {
            token tok(*i, "punctuation");
            tokens.push_back(tok);
        }
    }
    return tokens;
}
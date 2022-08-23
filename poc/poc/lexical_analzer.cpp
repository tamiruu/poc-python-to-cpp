#include "lexical_analzer.h"

void clean_tab_and_space(std::vector<std::string>& code) {
    for (std::vector<std::string>::iterator i = code.begin(); i != code.end(); ++i)
    {
        std::string content = "";
        for (int j = 0; j < i->size(); j++)
        {
            if (i[j] != " " && i[j] != "\t")
            {
                content += i[j];
            }
        }
        *i = content;
    }
}

void clean_comments(std::vector<std::string>& code) {
    for (std::vector<std::string>::iterator i = code.begin(); i != code.end(); ++i)
    {
        std::string content = "";
        for (int j = 0; j < i->size(); j++)
        {
            if (i[j] != "#" )
            {
                content += i[j];
            }
            else {
                break;
            }
        }
        content += "\n";
        *i = content;
    }
} 

token::token(std::string value, std::string type) {
    this->token_value = value;
    this->type = type;
}

std::vector<token> tokenizer(std::vector<std::string>& code) {
    std::vector<token> tokens;
    clean_comments(code);
    
    clean_tab_and_space(code);
    for (std::vector<std::string>::iterator i = code.begin(); i != code.end(); ++i)
    {
        for (int j = 0; j < i->size(); j++)
        {
            if (is_keywords(i[j]))
            {
                token tok(i[j], "keyword");
            }
            else if (is_operator(i[j]))
            {
                token tok(i[j], "operator");
            }
            else if ((i[j]))
            {

            }
        }
    }
}
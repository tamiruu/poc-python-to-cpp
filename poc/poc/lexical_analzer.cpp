#include "lexical_analzer.h"

std::vector<std::string> clean_tab_and_space(std::vector<std::string>& code) {
    std::vector<std::string> words;
    for (std::vector<std::string>::iterator i = code.begin(); i != code.end(); ++i)
    {
        std::string content = "";
        for (int j = 0; j < i->size(); j++)
        {
            if (i[j] != " " && i[j] != "\t")
            {
                content += i[j];
            }
            else
            {
                if (content != "")
                {
                    words.push_back(content);
                    content = "";
                }
            }// hi iuwe dwejniof
        }
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
        }
        else if (is_operator(*i))
        {
            token tok(*i, "operator");
        }
        else if () {

        }
        else if (checkType(*i) == "int" || checkType(*i) == "float" || checkType(*i) == "str")
        {
            token tok(*i, "constant");
        }
    }
    return tokens;
}
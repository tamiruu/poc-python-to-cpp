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
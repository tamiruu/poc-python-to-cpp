#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "helper.h"
//cleaners
class token
{
public:
	token(std::string value, std::string type);
private:
	std::string token_value;
	std::string type;
};

std::vector<std::string> clean_tab_and_space(std::vector<std::string>& code);
void clean_comments(std::vector<std::string>& code);
std::vector<token> tokenizer(std::vector<std::string>& code);
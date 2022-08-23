#pragma once
#include <iostream>

bool checkName(std::string& name, int pos, const std::string& file_content);//function to check name of variable/function

std::string checkType(std::string value);
bool is_keywords(std::string word);
bool is_operator(std::string word);
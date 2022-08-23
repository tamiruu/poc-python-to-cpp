#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Symbol_table.h"
bool checkName(std::string& name, int pos, const std::string& file_content);//function to check name of variable/function

std::string checkType(std::string value);

bool is_keywords(std::string word);
bool is_operator(std::string word);
bool is_punctuation(std::string word);



std::string checkScope(int line, const std::string& name, const std::string& file_content, Symbol_table& table);


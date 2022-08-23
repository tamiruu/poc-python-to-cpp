#pragma once
#include <iostream>
#include <fstream>
#include <vector>
//cleaners
void clean_tab_and_space(std::vector<std::string>& code);
void clean_comments(std::vector<std::string>& code);
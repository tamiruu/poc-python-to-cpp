#pragma once
#include <iostream>
#include <vector>
#include "helper.h"
#include "syntax analyzer.h"
#include "lexical_analzer.h"
std::string python_to_c_function_printf(std::vector<token> function, Symbol_table& table);
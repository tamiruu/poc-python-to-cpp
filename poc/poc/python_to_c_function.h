#pragma once
#include <iostream>
std::string python_to_c_function(std::string content){
	if (content == "print")
	{
		return "printf";
	}
	return "error";
}
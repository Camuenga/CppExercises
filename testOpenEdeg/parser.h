#ifndef _PARSER_H
#define _PARSER_H
#include <cctype> 
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>

namespace parser{
	
	struct parserS{
		unsigned short sizeTag {0},amountQuerie{0};
		std::string finalTag,finalQuerie;
	};
	int checkTagSintaxe(const std::string&);
	int checkTagQuerie(const std::string&);
	int ignoringSpace(const std::string&,unsigned short);
}                                               	

#endif
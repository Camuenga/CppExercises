#include "parser.h"

int parser::checkTagSintaxe(const std::string& TagLine){
	
	unsigned short start {0},openTag{0},openTagPosition {0},closeTag{0};
		
	if((TagLine.at(start) == '<')){
		
		while(start < TagLine.size()){
			if(TagLine.at(start) == '<'){
				++openTag;
				if(openTag % 2 == 0){
					openTagPosition = start;
				}
			}
			++start;
		}
	//----------------------------------------------------------------------------------------------------------------	
		std::cout << "<" << openTag ;
		std::cout << std::endl;	
	//----------------------------------------------------------------------------------------------------------------
		start = 0;
		while(start < TagLine.size()){
			if(TagLine.at(start) == '>'){
				++closeTag;
			}
			++start;
		}
		std::cout << ">" << closeTag;
		
	}else{std::cerr << "[sintaxe error:: there is no '<' at begin of tag declaration ] " << std::endl;}	
	
	std::cout << std::endl;
	//------------------------------------------------------------------------------------------------------------------

	if(openTag % 2 == 1 || closeTag % 2 == 1){std::cerr << "[sintaxe error:: tag declarion short '<' or '>' ]" << std::endl;}
	
	if((openTag % 2 == 0) && (closeTag % 2 == 0)){
		parser::ignoringSpace(TagLine,openTagPosition);
	}	
}

int parser::ignoringSpace(const std::string& tagLine,unsigned short tagPosition){
	
	unsigned short start = ++tagPosition,tagBarPosition{0},tagBarAmount{0},tagCharAmount{0};
	while(tagPosition < tagLine.size()){
		if(tagLine.at(tagPosition) == '/'){
			tagBarPosition = tagPosition;
			tagBarAmount++;
		}
		tagPosition++;
	}
	if(tagBarAmount == 1){
		while(start < tagBarPosition){
			if(tagLine.at(start) != ' '){
				tagCharAmount++;
			}
			start++;
		}
		if(tagCharAmount){
			std::cerr << "[sintaxe error:: undefined values before '/' close bar tag] '" << tagLine.at(start) << "'" << std::endl;	
		}else{
			//std::cout << "Declaration is rigth" << std::endl;
			return 1;
		}
	}else{
		//std::cerr << "[sintaxe error:: '/' close bar tag was not found it '" << tagLine.at(start) << "'" << std::endl;
		return 0;	
	}
}
int parser::checkTagQuerie(const std::string& finalTag){

	std::stringstream ss;
	for (char c : finalTag) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            ss << c;
        } else {
            ss << " ";
        }
    }

    int number;
    while (ss >> number) {
        std::cout << "Found number: " << number << std::endl;
    }
	
/*	if(finalTag.find(finalQuerie) != std::string::npos){
		std::cerr << "found it" << std::endl;
		return 1;
	}else{
		std::cerr << "Was not found it" << std::endl;
		return 0;
	}*/
	
}



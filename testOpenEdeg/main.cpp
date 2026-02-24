#include "parser.h"

int main()
{
	parser::parserS *tag = new parser::parserS;
	while(true){
		std::cin >> tag->sizeTag >> tag->amountQuerie;
			if((tag->sizeTag == 1 || tag->amountQuerie <= 20) && (tag->sizeTag == 1 || tag->amountQuerie <= 20))
				break;
	}
		
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::vector<std::string>TagsVector(tag->sizeTag);	
	unsigned short i_Tag{0};
	while(i_Tag < tag->sizeTag){
		std::getline(std::cin,TagsVector.at(i_Tag));
		tag->finalTag.append(TagsVector.at(i_Tag));
		i_Tag++;
	}                          
	unsigned short errorMsg = parser::checkTagSintaxe(tag->finalTag);	
	unsigned short i_Querie{0};
	
	std::vector<std::string>TagQuerie(tag->sizeTag);	
	while(i_Querie < tag->sizeTag){
		std::getline(std::cin,TagQuerie.at(i_Querie));
		tag->finalQuerie.append(TagQuerie.at(i_Querie));
		i_Querie++;	
	}
	
/*	if(errorMsg){
		parser::checkTagQuerie(tag->finalTag);
	}else{
		std::cerr << "declaration errror" << std::endl;
	}
	*/
	delete tag;
	tag = nullptr;
	
	return 0;	
}

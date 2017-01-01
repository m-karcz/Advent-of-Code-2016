#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <climits>

int main(){
	std::map<std::size_t, std::map<char, int>> counter;
	std::fstream input;
	input.open("6a.txt");
	std::string line;
	while(std::getline(input, line)){
		for(std::size_t i=0; i<line.size(); i++){
			counter[i][line[i]]++;
		}
	}
	input.close();
	for(auto& column : counter){
		std::pair<char, int> most_common=std::make_pair<char, int>('\0', 0);
		for(auto& pair : column.second){
			if(most_common.second < pair.second)
				most_common=pair;
		}
		std::cout << most_common.first;
	}	
	std::cout << std::endl;
	return 0;
}

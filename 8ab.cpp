#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>
#include <regex>
#include <memory>
#include <utility>
#include <boost/lexical_cast.hpp>


struct size{
	static const std::size_t x=50;
	static const std::size_t y=6;
};

enum class command{
	rect,
	rotate_row,
	rotate_col,
	unknown
};

class Screen{
public:
	void make_move(std::string& line);	
	void show();
	Screen();
private:
	std::array<std::array<bool, size::x>, size::y> display;
	command get_command(std::string line);
	std::pair<int, int> get_2_values_from_regex(std::string& line, std::regex regex);
	std::pair<int, int> get_rect_size(std::string& line);
	std::pair<int, int> get_rotate_params(std::string& line);
	void make_rect(std::pair<int, int> args);
	void rotate_col(std::pair<int, int> args);
	void rotate_row(std::pair<int, int> args);
};


command Screen::get_command(std::string line){
	std::regex rect_check("^rect.*$");
	std::regex row_check("^rotate row.*$");
	std::regex col_check("^rotate col.*$");
	if(std::regex_match(line, rect_check))
		return command::rect;
	if(std::regex_match(line, row_check))
		return command::rotate_row;
	if(std::regex_match(line, col_check))
		return command::rotate_col;
	return command::unknown;
}

Screen::Screen(){
	for(auto& arr : display)
		arr.fill(false);
}

std::pair<int, int> Screen::get_2_values_from_regex(std::string& line, std::regex regex){
	std::smatch result;
	std::regex_search(line, result, regex);
	//std::cout << result[1] << "==" << result[2] << std::endl;
	return std::make_pair<int,int>(boost::lexical_cast<int>(result[1]),boost::lexical_cast<int>(result[2]));
}

std::pair<int, int> Screen::get_rect_size(std::string& line){
	return std::move(get_2_values_from_regex(line, std::regex("^rect (\\d+)x(\\d+)$")));
}

std::pair<int, int> Screen::get_rotate_params(std::string& line){
	return std::move(get_2_values_from_regex(line, std::regex("^rotate \\w+ \\w=(\\d+) by (\\d+)")));
}

void Screen::make_rect(std::pair<int, int> args){
	for(int y=0; y<args.second; y++)
		for(std::size_t x=0; x<args.first; x++)
			this->display[y][x]=true;
	return;
}

void Screen::rotate_col(std::pair<int, int> args){
	std::array<bool, size::y> copy;
	auto x=args.first;
	auto move=args.second;
	for(std::size_t y=0; y<size::y; y++)
		copy[y]=display[y][x];
	for(std::size_t y=0; y<size::y; y++)
		display[(y+move)%size::y][x]=copy[y];
	return;
}

void Screen::rotate_row(std::pair<int, int> args){
	std::array<bool, size::x> copy;
	auto y=args.first;
	auto move=args.second;
	for(std::size_t x=0; x<size::x; x++)
		copy[x]=display[y][x];
	for(std::size_t x=0; x<size::x; x++)
		display[y][(x+move)%size::x]=copy[x];
	return;
}

void Screen::make_move(std::string& line){
	
	switch(this->get_command(line)){
		case command::rect:
			this->make_rect(std::move(get_rect_size(line)));
			break;	
		case command::rotate_col:
			this->rotate_col(std::move(get_rotate_params(line)));
			break;
		case command::rotate_row:
			this->rotate_row(std::move(get_rotate_params(line)));
			break;
		default:
			std::cout << "sth went wrong";
	}
	return;
}

void Screen::show(){
	for(std::size_t y=0; y<size::y; y++){
		for(std::size_t x=0; x<size::x; x++){
			std::cout << (display[y][x] ? "#" : " ");
		}
		std::cout << std::endl;
	}
	std::cout << std::accumulate(display.begin(), display.end(), 0, [](int sum, auto& arr){
		return sum+std::accumulate(arr.begin(), arr.end(), 0, [](int interior_sum, bool val){
			return interior_sum+(val?1:0);
		});
	}) << std::endl;
}



int main(){
	std::fstream input;
	input.open("8.txt");
	std::string line;
	Screen screen;
	while(std::getline(input, line)){
		screen.make_move(line);
	}
	screen.show();
	return 0;
}

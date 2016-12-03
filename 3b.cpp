#include <iostream>
#include <sstream>
#include <fstream>
#include <array>
#include <algorithm>

int main(){
  std::ifstream input; 
  input.open("input/3.txt");
  std::array<std::string,3> lines;
  int number_of_triangles=0;
  while(std::getline(input, lines[0])){
    std::array<std::array<int,3>,3> numbers;
    std::getline(input, lines[1]);
    std::getline(input, lines[2]);
    auto i = {0,1,2};
    for(int x : i){
      std::stringstream ss(lines[x]);
      for(int y : i){
        ss >> numbers[y][x];
      }
    }
    for(int y : i){
      std::sort(numbers[y].begin(), numbers[y].end());
      if(numbers[y][0] + numbers[y][1] > numbers[y][2]){
        number_of_triangles++;
      }
    }
  }
  std::cout << "Number of triangles: " << number_of_triangles << std::endl;
  input.close();
}

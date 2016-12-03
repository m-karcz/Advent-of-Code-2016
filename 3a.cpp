#include <iostream>
#include <sstream>
#include <fstream>
#include <array>
#include <algorithm>

int main(){
  std::ifstream input; 
  input.open("input/3.txt");
  std::string line;
  int number_of_triangles=0;
  while(std::getline(input, line)){
    std::stringstream ss(line);
    std::array<int, 3> numbers;
    ss >> numbers[0];
    ss >> numbers[1];
    ss >> numbers[2];
    std::sort(numbers.begin(), numbers.end());
    if(numbers[0]+numbers[1]>numbers[2])
      number_of_triangles++;
  }
  std::cout << "Number of triangles: " << number_of_triangles << std::endl;
  input.close();
}

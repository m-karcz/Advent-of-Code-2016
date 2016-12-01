#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

int modn(int num, int n){
  return num>0 ? num%n : (n+num)%n; 
}

int mod4(int num){
  return modn(num, 4);
}


int main(){
  std::ifstream input;
  std::string input_str;
  int x=0;
  int y=0;
  int dir=0;
  input.open("input/1.txt");
  std::getline(input, input_str);
  input.close();
  std::list<std::string> movements;
  boost::algorithm::split(movements, input_str, boost::is_any_of(", "), boost::token_compress_on);
  for(std::string& move : movements){
    dir = mod4(move.c_str()[0]=='R' ? dir+1 : dir-1);
    int distance=boost::lexical_cast<int>(move.substr(1));
    switch(dir){
      case 0:
        y+=distance;
        break;
      case 1:
        x+=distance;
        break;
      case 2:
        y-=distance;
        break;
      case 3:
        x-=distance;
        break; 
    }
  } 
  std::cout << "manhattan_norm: " << std::abs(x)+std::abs(y) << std::endl;
}

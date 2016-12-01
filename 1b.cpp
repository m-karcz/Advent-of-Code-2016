#include <iostream>
#include <fstream>
#include <list>
#include <cmath>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <set>

int modn(int num, int n){
  return num>0 ? num%n : (n+num)%n; 
}

int mod4(int num){
  return modn(num, 4);
}

struct Point{
  Point(int x, int y):x(x),y(y){}
  int x;
  int y;
  bool operator<(const Point& other) const{
    return this->x > other.x ? false : (this->x == other.x ? this->y < other.y : true);
  }
};


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
  std::set<Point> points;
  points.emplace(Point(0,0));
  boost::algorithm::split(movements, input_str, boost::is_any_of(", "), boost::token_compress_on);
  for(std::string& move : movements){
    dir = mod4(move.c_str()[0]=='R' ? dir+1 : dir-1);
    int distance=boost::lexical_cast<int>(move.substr(1));
    int* ptr=nullptr;
    int sign;
    switch(dir){
      case 0:
        ptr=&y;
        sign=1;
        break;
      case 1:
        ptr=&x;
        sign=1;
        break;
      case 2:
        ptr=&y;
        sign=-1;
        break;
      case 3:
        ptr=&x;
        sign=-1;
        break;
    }
    while(distance>0){
      distance--;
      *ptr+=sign;
      if(points.find(Point(x,y))!=points.end()){
        std::cout << "Distance: " <<  std::abs(x)+std::abs(y) << std::endl;
        return 0;
      }
      points.emplace(Point(x,y));
    }
  }
}

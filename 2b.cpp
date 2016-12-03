#include <iostream>
#include <fstream>
#include <array>

//    1
//  2 3 4
//5 6 7 8 9
//  101112
//    13
class Hand{
public:
  void operator()(const char c){
    switch(c){
      case 'D':
        y = y==4 ? y : location_to_value(x, y+1) ? y+1 : y;
        return; 
      case 'U':
        y = y==0 ? y : location_to_value(x, y-1) ? y-1 : y;
        return;
      case 'L':
        x = x==0 ? x : location_to_value(x-1, y) ? x-1 : x;
        return;
      case 'R':
        x = x==4 ? x : location_to_value(x+1, y) ? x+1 : x;
        return;
      default:
        return;
    }
  }
private:
  int x=0;
  int y=2;
  static std::array<std::array<int,5>,5> arr;
  friend std::ostream& operator<<(std::ostream& stream, const Hand& hand);
  int location_to_value(int x, int y) const{
    return arr[y][x];
  }
  int location_to_value() const{
    return arr[y][x];
  }
};

std::array<std::array<int,5>,5> Hand::arr={std::array<int,5>{0,0,1,0,0},{0,2,3,4,0},{5,6,7,8,9},{0,10,11,12,0},{0,0,13,0,0}};

std::ostream& operator<<(std::ostream& stream, const Hand& hand){
  return stream << (hand.location_to_value()<9 ? std::to_string(hand.location_to_value()) : std::string(1,'A'+hand.location_to_value()-10));
}

int main(){
  std::ifstream input;
  input.open("input/2.txt");
  std::string line;
  std::cout << "Code: ";
  Hand hand;
  while(std::getline(input, line)){
    for(char c : line){
      hand(c);
    }
    std::cout << hand;
  }
  std::cout << std::endl;
  return 0;
}

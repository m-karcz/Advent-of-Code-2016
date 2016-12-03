#include <iostream>
#include <fstream>

class Hand{
public:
  void operator()(const char c){
    switch(c){
      case 'D':
        y = y==2 ? 2 : y+1;
        return; 
      case 'U':
        y = y==0 ? 0 : y-1;
        return;
      case 'L':
        x = x==0 ? 0 : x-1;
        return;
      case 'R':
        x = x==2 ? 2 : x+1;
        return;
      default:
        return;
    }
  }
private:
  int x=1;
  int y=1;
  friend std::ostream& operator<<(std::ostream& stream, const Hand& hand);
};

std::ostream& operator<<(std::ostream& stream, const Hand& hand){
  return stream << hand.x%3+hand.y*3+1; 
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

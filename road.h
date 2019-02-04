#ifndef Road_hpp
#define Road_hpp
#include <string>


class Road {
  int addr;
  std::string owner;

 public:
  Road(int addr);
  void built(std::string builder);
  std::string getOwner();
  std::string printRoad();
  int getAddr();

};


#endif


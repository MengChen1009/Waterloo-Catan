#ifndef _BUILDER_H_
#define _BUILDER_H_
#include "observer.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Builder: public Observer{
  std::string color;
  int pts;
  std::vector<int> resource; // B,E,G,H,W                                            
  std::vector<int> roads;
  std::map<int, std::string> buildings;

 public:
  Builder(std::string color);
  void notified(TileType t, int n) override;
  void reset();
  void set(std::string s);
  std::string save();
  void printStatus();
  void printBuildings();
  void resbuilt(int address);
  bool buildres(int address);
  bool buildroad(int path);
  bool improve(int address);
  void trade(std::string take, std::string give, std::shared_ptr<Builder> b);
  std::string getColor();
  int getPts();
  void gainResource(int n);
  void loseResource(int n);
  bool hasResource(int n);
  int numResource();
  ~Builder();
};

#endif

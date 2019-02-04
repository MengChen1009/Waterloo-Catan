#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "residence.h"
#include "subject.h"
#include "tile.h"
#include "road.h"

class Builder;

const int numRes = 54;
const int numRoads = 72;
const int numTiles = 19;
class Board {

  std::vector<std::shared_ptr<Residence>> res; //smart_ptr will be nullptr by default.
  std::vector<std::shared_ptr<Road>> roads; //smart_ptr will be nullptr by default.
  std::vector<std::shared_ptr<Tile>> tiles;
  int seed = 0;
  int geese = 19;
  
  
  
  std::string nspace(int n) const;
  void printTnum(int t) const;
  void print1(int *ad, int *rd) const;
  void printTV(int t) const;
  void print2(int *t) const;
  void print3(int *rd, const int t) const;
  void print4(const int t) const;
  int range(int gen);
  std::string ToString(int c);
  TileType intToType(int i);
    
  public:
  Board();
  void init();
  void setseed(int seed);
  void makeboard(std::shared_ptr<std::istream> inp);
  void load(std::shared_ptr<std::istream> inp, std::vector<std::shared_ptr<Builder>> &b);
  bool addrAvailable(int address); 
  bool pathAvailable(int path);
  std::shared_ptr<Residence> getEmpty(int address);
  void attach_to_tile(std::shared_ptr<Residence> r);
  void tile_chosen(int n);
  void print() const;
  std::shared_ptr<Residence> getRes(int address);
  void dettach_from_tile(std::shared_ptr<Residence> r);
  std::shared_ptr<Road> getRoad(int address);
  void buildRoad(int address, std::shared_ptr<Builder> b);
  std::string save();
  bool geese_to_tile(int addr, std::string current);
  void setGeese(int g);
  void createB(std::shared_ptr<Builder> b, int n);
  void improve(int n, char type);
  ~Board();
 
};

#endif

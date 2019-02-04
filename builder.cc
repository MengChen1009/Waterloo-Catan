#include "builder.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include "tiletype.h"
using namespace std;

const vector<int> rr0 = {1, 2};
const vector<int> rr1 = {0, 3, 6};
const vector<int> rr2 = {0, 4, 7};
const vector<int> rr3 = {1, 5, 6};
const vector<int> rr4 = {2, 7, 8};
const vector<int> rr5 = {3, 9, 13};
const vector<int> rr6 = {1, 3, 10, 14};
const vector<int> rr7 = {2, 4, 10, 15};
const vector<int> rr8 = {4, 11, 16};
const vector<int> rr9 = {5, 12, 13};
const vector<int> rr10 = {6, 7, 14, 15};
const vector<int> rr11 = {8, 16, 17};
const vector<int> rr12 = {9, 20};
const vector<int> rr13 = {5, 9, 18, 21};
const vector<int> rr14 = {6, 10, 18, 22};
const vector<int> rr15 = {7, 10, 19, 23};
const vector<int> rr16 = {8, 11, 19, 24};
const vector<int> rr17 = {11, 25};
const vector<int> rr18 = {13, 14, 21, 22};
const vector<int> rr19 = {15, 16, 23, 24};
const vector<int> rr20 = {12, 26, 29};
const vector<int> rr21 = {13, 18, 26, 30};
const vector<int> rr22 = {14, 18, 27, 31};
const vector<int> rr23 = {15, 19, 27, 32};
const vector<int> rr24 = {16, 19, 28, 33};
const vector<int> rr25 = {17, 28, 34};
const vector<int> rr26 = {20, 21, 29, 30};
const vector<int> rr27 = {22, 23, 31, 32};
const vector<int> rr28 = {24, 25, 33, 34};
const vector<int> rr29 = {20, 26, 37};
const vector<int> rr30 = {21, 26, 35, 38};
const vector<int> rr31 = {22, 27, 35, 39};
const vector<int> rr32 = {23, 27, 36, 40};
const vector<int> rr33 = {24, 28, 36, 41};
const vector<int> rr34 = {25, 28, 42};
const vector<int> rr35 = {30, 31, 38, 39};
const vector<int> rr36 = {32, 33, 40, 41};
const vector<int> rr37 = {29, 43, 46};
const vector<int> rr38 = {30, 35, 43, 47};
const vector<int> rr39 = {31, 35, 44, 48};
const vector<int> rr40 = {32, 36, 44, 49};
const vector<int> rr41 = {33, 36, 45, 50};
const vector<int> rr42 = {34, 45, 51};
const vector<int> rr43 = {37, 38, 46, 47};
const vector<int> rr44 = {39, 40, 48, 49};
const vector<int> rr45 = {41, 42, 50, 51};
const vector<int> rr46 = {37, 43, 54};
const vector<int> rr47 = {38, 43, 52, 55};
const vector<int> rr48 = {39, 44, 52, 56};
const vector<int> rr49 = {40, 44, 50, 57};
const vector<int> rr50 = {41, 45, 53, 58};
const vector<int> rr51 = {42, 45, 59};
const vector<int> rr52 = {47, 48, 55, 56};
const vector<int> rr53 = {49, 50, 57, 58};
const vector<int> rr54 = {46, 60};
const vector<int> rr55 = {47, 52, 60, 63};
const vector<int> rr56 = {48, 52, 61, 64};
const vector<int> rr57 = {49, 53, 61, 65};
const vector<int> rr58 = {50, 53, 62, 66};
const vector<int> rr59 = {51, 62};
const vector<int> rr60 = {54, 55, 63};
const vector<int> rr61 = {56, 57, 64, 65};
const vector<int> rr62 = {58, 59, 66};
const vector<int> rr63 = {55, 60, 67};
const vector<int> rr64 = {56, 61, 67, 69};
const vector<int> rr65 = {57, 61, 68, 70};
const vector<int> rr66 = {58, 62, 68};
const vector<int> rr67 = {63, 64, 69};
const vector<int> rr68 = {65, 66, 70};
const vector<int> rr69 = {64, 67, 71};
const vector<int> rr70 = {65, 68 ,71};
const vector<int> rr71 = {69, 70};

const vector<vector<int>> road_road = {
  rr0, rr1, rr2, rr3, rr4, rr5, rr6, rr7, rr8, rr9, 
  rr10, rr11, rr12, rr13, rr14, rr15, rr16, rr17, rr18, rr19,
  rr20, rr21, rr22, rr23, rr24, rr25, rr26, rr27, rr28, rr29,
  rr30, rr31, rr32, rr33, rr34, rr35, rr36, rr37, rr38, rr39,
  rr40, rr41, rr42, rr43, rr44, rr45, rr46, rr47, rr48, rr49,
  rr50, rr51, rr52, rr53, rr54, rr55, rr56, rr57, rr58, rr59,
  rr60, rr61, rr62, rr63, rr64, rr65, rr66, rr67, rr68, rr69,
  rr70, rr71 };


const vector<int> ar0 = {0, 1};
const vector<int> ar1 = {0, 2};
const vector<int> ar2 = {3, 5};
const vector<int> ar3 = {1, 3, 6};
const vector<int> ar4 = {2, 4, 7};
const vector<int> ar5 = {4, 8};
const vector<int> ar6 = {9, 12};
const vector<int> ar7 = {5, 9, 13};
const vector<int> ar8 = {6, 10, 14};
const vector<int> ar9 = {7, 10, 15};
const vector<int> ar10 = {8, 11, 16};
const vector<int> ar11 = {11, 17};
const vector<int> ar12 = {12, 20};
const vector<int> ar13 = {13, 18, 21};
const vector<int> ar14 = {14, 18, 22};
const vector<int> ar15 = {15, 19, 23};
const vector<int> ar16 = {16, 19, 24};
const vector<int> ar17 = {17, 25};
const vector<int> ar18 = {20, 26, 29};
const vector<int> ar19 = {21, 26, 30};
const vector<int> ar20 = {22, 27, 31};
const vector<int> ar21 = {23, 27, 32};
const vector<int> ar22 = {24, 28, 33};
const vector<int> ar23 = {25, 28, 34};
const vector<int> ar24 = {29, 37};
const vector<int> ar25 = {30, 35, 38};
const vector<int> ar26 = {31, 35, 39};
const vector<int> ar27 = {32, 36, 40};
const vector<int> ar28 = {33, 36, 41};
const vector<int> ar29 = {34, 42};
const vector<int> ar30 = {37, 43, 46};
const vector<int> ar31 = {38, 43, 47};
const vector<int> ar32 = {39, 44, 48};
const vector<int> ar33 = {40, 44, 49};
const vector<int> ar34 = {41, 45, 50};
const vector<int> ar35 = {42, 45, 51};
const vector<int> ar36 = {46, 54};
const vector<int> ar37 = {47, 52, 55};
const vector<int> ar38 = {48, 52, 56};
const vector<int> ar39 = {49, 53, 57};
const vector<int> ar40 = {50, 53, 58};
const vector<int> ar41 = {51, 59};
const vector<int> ar42 = {54, 60};
const vector<int> ar43 = {55, 60, 63};
const vector<int> ar44 = {56, 61, 64};
const vector<int> ar45 = {57, 61, 65};
const vector<int> ar46 = {58, 62, 66};
const vector<int> ar47 = {59, 62};
const vector<int> ar48 = {63, 67};
const vector<int> ar49 = {64, 67, 69};
const vector<int> ar50 = {65, 68, 70};
const vector<int> ar51 = {66, 68};
const vector<int> ar52 = {69, 71};
const vector<int> ar53 = {70, 71};


const vector<vector<int>> addr_road = {
  ar0, ar1, ar2, ar3, ar4, ar5, ar6, ar7, ar8, ar9, ar10,
  ar10, ar11, ar12, ar13, ar14, ar15, ar16, ar17, ar18, ar19, ar20,
  ar20, ar21, ar22, ar23, ar24, ar25, ar26, ar27, ar28, ar29, ar30,
  ar30, ar31, ar32, ar33, ar34, ar35, ar36, ar37, ar38, ar39, ar40,
  ar40, ar41, ar42, ar43, ar44, ar45, ar46, ar47, ar48, ar49, ar50,
  ar51, ar52, ar53 };

Builder::Builder(string color): color{color} {
  pts = 0;
  resource = {0, 0, 0, 0, 0};
}

void Builder::reset() {
  pts = 0;
  resource.clear();
  roads.clear();
  buildings.clear();
}

void Builder::set(string s){
  int i = 0;
  int n;
  char c;
  stringstream ss{s};
  // load resource                                                                                                                 
  while (i < 5) {
    ss >> n;
    resource[i] = n;
    ++i;
  }
  ss >> c; // load roads
  while (ss >> n) {
    roads.emplace_back(n);
  }
  ss.clear(); // load buildings
  ss.ignore();
  int j = 0;
  while (ss >> n) {
    ss >> c;
    string t;
    if (c == 'B') {
      t = "Basement";
	  ++pts;
    } else if (c == 'H') {
      t = "House";
	  pts += 2;
    } else if (c == 'T') {
      t = "Tower";
	  pts += 3;
    }
    buildings.insert( pair<int, string>(n, t));
    ++j;
  }
}

string Builder::save() {
  string s = "";
  int i = 0;
  while (i < 5) {
    if (i != 0) {
      s += " ";
    }
    s += to_string(resource[i]);
    ++i;
  }
  s += " r";
  int size = roads.size();
  i = 0;
  while (i < size) {
    s += " ";
    s += to_string(roads[i]);
    ++i;
  }
  s += " h";
  string tmp;
  map<int, string>::iterator r = buildings.begin();
  while(r != buildings.end()) {
    s += " ";
    int inth = r->first;
	tmp = to_string(inth);
    s += tmp;
    s += " ";
    s += (r->second)[0];
    ++r;
  }
  return s;
}
    
void Builder::printStatus() {
  cout << color << " has " << pts <<
    "  building points, " << resource[0] <<
    " brick, " << resource[1] << " energy,\n" <<
    resource[2] << " glass, " << resource[3] <<
    " heat, and " << resource[4] << " WiFi." << endl;
}

void Builder::printBuildings() {
  cout << color << " has built:" << endl;
  map<int, string>::iterator i = buildings.begin();
  while (i != buildings.end()) {
    cout << i->first << " " << (i->second)[0] << endl;
    ++i;
  }
}

void Builder::notified(TileType t, int n) {
  resource[t] += n;
  cout << "Builder " << color << " gained:" << endl;
  string s = ToString(t);
  cout << n << " " << s << endl;
}

void Builder::resbuilt(int address) {
	buildings.insert( pair<int, string>(address, "Basement"));
	++pts;
}

bool Builder::buildres(int address) {
  if ((resource[0] > 0) && (resource[1] > 0) &&
      (resource[2] > 0) && (resource[4] > 0)) {
    int i = 0;
    int bsize = roads.size();
    while (i < bsize) {
      int j = 0;
      int rsize = road_road[address].size();
      while (j < rsize) {
        if (roads[i] == road_road[address][j]) {
          buildings.insert( pair<int, string>(address, "Basement"));
          --resource[0];
          --resource[1];
          --resource[2];
          --resource[4];
          ++pts;
          return true;
        }
        ++j;
      }
      ++i;
    }
    cout << "You cannot build here." << endl;
  }
    cout << "You do not have enough resources." << endl;
    return false;
}

bool Builder::improve(int address) {
  string s = buildings[address];
  if (s == "Basement") {
    if ((resource[2] > 1) && (resource[3] > 2)) {
      buildings[address] = "House";
      resource[2] -= 2;
      resource[3] -= 3;
      ++pts;
      return true;
    } else {
      cout << "You do not have enough resources." << endl;
      return false;
    }
  } else if (s == "House") {
    if ((resource[0] > 2) && (resource[1] > 1) &&
        (resource[2] > 1) && (resource[3] > 1) &&
        (resource[4] > 0)) {
      buildings[address] = "Tower";
      resource[0] -= 3;
      resource[1] -= 2;
      resource[2] -= 2;
      resource[3] -= 2;
      --resource[4];
      ++pts;
      return true;
    } else {
      cout << "You do not have enough resources." << endl;
      return false;
    }
  } 
  return false;
}

bool Builder::buildroad(int address) {
  if ((resource[3] > 0) && (resource[4] > 0)) {
    int i = 0;
    int bsize = roads.size();
    while (i < bsize) {
      int j = 0;
      int rsize = road_road[address].size();
      while (j < rsize) {
        if (roads[i] == road_road[address][j]) {
          roads.emplace_back(address);
          --resource[3];
          --resource[4];
          return true;
        }
        ++j;
      }
      ++i;
    }
    cout << "You cannot build here." << endl;
  }
    cout << "You do not have enough resources." << endl;
    return false;
}

void Builder::trade(string take, string give, shared_ptr<Builder> b) {

  ++resource[ToTileType(take)];
  --resource[ToTileType(give)];
  b->gainResource(ToTileType(give));
  b->loseResource(ToTileType(take));
  cout << getColor() << " offers " << b->getColor() << " one " << give << " for one " << take << endl;
}
  
string Builder::getColor() {
  return color;
}
  
int Builder::getPts() {
  return pts;
}
  
void Builder::gainResource(int n) {
  ++resource[n];
}
  
void Builder::loseResource(int n) {
  --resource[n];
}

bool Builder::hasResource(int n) {
    if (resource[n] > 0) {
        return true;
    } else {
        return false;
    }
}

int Builder::numResource() {
    int i = 0;
    int n = 0;
    while (i < 5) {
        n += resource[i];
        ++i;
    }
    return n;
}

Builder::~Builder() {}


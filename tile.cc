#include "tile.h"
#include <string>
#include <vector>
using namespace std;

const vector<int> v0 = {0, 1, 3, 4, 8, 9};
const vector<int> v1 = {2, 3, 7, 8, 13, 14};
const vector<int> v2 = {4, 5, 9, 10, 15, 16};
const vector<int> v3 = {6, 7, 12, 13, 18, 19};
const vector<int> v4 = {8, 9, 14, 15, 20, 21};
const vector<int> v5 = {10, 11, 16, 17, 22, 23};
const vector<int> v6 = {13, 14, 19, 20, 25, 26};
const vector<int> v7 = {15, 16, 21, 22, 27, 28};
const vector<int> v8 = {18, 19, 24, 25, 30, 31};
const vector<int> v9 = {20, 21, 26, 27, 32, 33};
const vector<int> v10 = {22, 23, 28, 29, 34, 35};
const vector<int> v11 = {25, 26, 31, 32, 37, 38};
const vector<int> v12 = {27, 28, 33, 34, 39, 40};
const vector<int> v13 = {30, 31, 36, 37, 42, 43};
const vector<int> v14 = {32, 33, 38, 39, 44, 45};
const vector<int> v15 = {34, 35, 40, 41, 46, 47};
const vector<int> v16 = {37, 38, 43, 44, 48, 49};
const vector<int> v17 = {39, 40, 45, 46, 50, 51};
const vector<int> v18 = {44, 45, 49, 50, 52, 53};

const vector<vector<int>> tilevector = {
  v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,
  v11, v12, v13, v14, v15, v16, v17, v18 };

Tile::Tile(TileType type, int addr, int value) : type{type},
	addr{addr}, value{value}, address{tilevector[addr]} {}

string Tile::print() const{
  return ToString(type);
}

TileType Tile::getTtype() const {
  return type;
}

int Tile::getValue() {
  return value;
}

bool Tile::addr_on_tile (int addr) {
  int i = 0;
  while (i < 6) {
    if (address[i] == addr) {
      return true;
    }
    ++i;
  }
  return false;
}

Tile::~Tile() {}

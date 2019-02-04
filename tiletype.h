#ifndef _TILETYPE_H_
#define _TILETYPE_H_
#include <string>
enum TileType {BRICK, ENERGY, GLASS, HEAT, WIFI, PARK};

std::string ToString(TileType v);

TileType ToTileType(std::string s);

#endif

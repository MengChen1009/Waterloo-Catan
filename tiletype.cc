#include "tiletype.h"

std::string ToString(TileType v) {
    switch (v)
    {
        case BRICK:   return "BRICK";
        case ENERGY:   return "ENERGY";
        case GLASS: return "GLASS";
        case HEAT: return "HEAT";
        case WIFI : return "WIFI";
		case PARK : return "PARK";
		default : return "ERROR";
    }
}

TileType ToTileType(std::string s) {
    if (s == "BRICK") {
        return BRICK;
    } else if (s == "ENERGY") {
        return ENERGY;
    } else if (s == "GLASS") {
        return GLASS;
    } else if (s == "HEAT") {
        return HEAT;
    } else if (s == "WIFI")  {
        return WIFI;
    } else {
		return PARK;
	}
}

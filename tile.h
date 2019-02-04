#ifndef _TILE_H_
#define _TILE_H_
#include "tiletype.h"
#include <string>
#include "subject.h"
#include <vector>

class Residence;
class Roads;

class Tile : public Subject {
	const TileType type;
	const int addr;
	const int value;
    const std::vector<int> address;
	//Residence
	
	public:
	Tile(TileType type, int addr, int value);
	std::string print() const;
    TileType getTtype() const override;
	int getValue();
        bool addr_on_tile (int addr);
		
	~Tile();
	
};

#endif

	


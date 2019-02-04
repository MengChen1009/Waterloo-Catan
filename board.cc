#include "board.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <memory>
#include "emptyresidence.h"
#include "basement.h"
#include "house.h"
#include "tower.h"
#include "tile.h"

using namespace std;

const int width = 9;

string Board::nspace(int n) const{
	string s = "";
	for (int i = 0; i < n; i++) {
		s += " ";
	}
    return s;
}

void Board::printTnum(int t) const{
	if (t < 10) {
		cout << " ";
	}
	cout << t;
}
void Board::print1(int *ad, int *rd) const{
	cout << (res[*ad])->printRes() << "--";
	++(*ad);
	cout << (roads[*rd])->printRoad() << "--" << (res[*ad])->printRes();
	++(*rd);
	++(*ad);
}

void Board::printTV(int t) const{
    cout << nspace(2);
    if ((tiles[t])->getValue() < 10) {
        cout << " ";
    }
	if ((tiles[t])->getValue() != 7) {
    cout << (tiles[t])->getValue();
	} else {
		cout << nspace(1);
	}
    
    cout << nspace(2);
}


void Board::print2(int *t) const {
    if (*t == geese) {
        cout << "|  GEESE  |";
    } else {
        cout << "|         |";
    }
    ++(*t);
}

void Board::print3(int *rd,const int t) const {
	cout << (roads[*rd])->printRoad() << "   ";
	++(*rd);
	printTnum(t);
	cout << "   ";
	cout << (roads[*rd])->printRoad();
	++(*rd);
}

void Board::print4(const int t) const{
	cout << "|" << nspace(2);
	cout << (tiles[t])->print() << nspace(width - (((tiles[t])->print()).length()) - 2);
	cout << "|";
}

int Board::range(int gen) {
	if ((gen == 2) || (gen == 7) || (gen == 12)) {
		return gen;
	}
	else if ((gen >= 3) && (gen <= 6)) {
		return 3;
	}
	else {
		return 8;
	}
}

std::string Board::ToString(int c)
{
	switch (c)
	{
	case 0:   return "Blue";
	case 1:   return "Red";
	case 2: return "Orange";
	default: return "Yellow";
	}
}

TileType Board::intToType(int i) {
    switch (i) {
        case 0:   return BRICK;
        case 1:   return ENERGY;
        case 2: return GLASS;
        case 3: return HEAT;
        case 4 : return WIFI;
		default : return PARK;
    }
}

bool Board::addrAvailable(int address) {
	char type = (res[address])->getRtype();
	if ((type != 'B') && (type != 'H') && (type != 'T')) {
		return true;
	}
	return false;
}

Board::Board() : res(numRes), tiles(numTiles), roads(numRoads){}

Board::~Board() {}

void Board::init() {
	vector<int> resources = {4, 4, 4, 3, 3, 1};
	map<int, int> count {{2, 1}, {3, 2},{4, 2},{5, 2},{6, 2}, {7, 1}, {8, 2},
	{9, 2}, {10, 2}, {11, 2},{12, 1}};
	srand(time(NULL));
	if (seed != 0){
		srand(seed);
	} 
	int val;
	int start = 2;
	int end = 12;
	int tt;
	int start2 = 0;
	int end2 = 5;
	
	for (int i = 0; i < numRes; ++i) {
		res[i] = (make_shared<Empty>(i));

    }
    for (int i = 0; i < numRoads; ++i) {
		roads[i] = (make_shared<Road>(i));
	}
	for (int i = 0; i < numTiles; ++i) {
		#ifdef DEBUG
			cout << "building tile " << i << endl;
		#endif
		

		while (true) {
			val = rand() % end + start;
			tt = rand() % end2 + start2;
			if  ((val != 7) && (tt != 5) && (resources[tt]) && (count[val])) {
				tiles[i] = (make_shared<Tile>(intToType(tt), i, val));
				--(resources[tt]);
				--(count[val]);
				if ( count[end] == 0) {
					--end;
				}
				if (count[start] == 0) {
					++start;
				}
				break;
			} else if (((val == 7) || (tt == 5)) && (resources[5])) {
				tiles[i] = (make_shared<Tile>(intToType(5), i, 7));
				--(resources[5]);
				--(count[7]);
				break;
			}
		}

	}
		
}



void Board::setseed(int seed) {
    this->seed = seed;
		
}



void Board::makeboard(shared_ptr<istream> inp) {
	//check if it's the file for the board or game
	int tiletype;
	int value;
	for (int i = 0; i < numRes; ++i) {
		res[i] = (make_shared<Empty>(i));
    }
    for (int i = 0; i < numRoads; ++i) {
		roads[i] = (make_shared<Road>(i));
	}
	for (int i = 0; i < numTiles; ++i) {
		*inp >> tiletype;
		*inp >> value;
		tiles[i] = (make_shared<Tile>(intToType(tiletype), i, value));
	}	
	//generate it
}




void Board::load(shared_ptr<istream> inp, vector<shared_ptr<Builder>> &b) {
	int dump;
	string need;
	getline(*inp, need);
	int br = 0;
	for (int i = 0; i < numRes; ++i) {
		res[i] = (make_shared<Empty>(i));
    }
    for (int i = 0; i < numRoads; ++i) {
		roads[i] = (make_shared<Road>(i));
	}
	
	
	for (br=br; br < 4; ++br) {	
		getline(*inp, need);
		stringstream needs(need);	
		
		for (int j = 0; j < 5; ++j) {
			needs >> dump;
		}

        string s;
		int rd;
		needs >> s;
		#ifdef DEBUG
		cout << s << "should be r." << endl;
		#endif
		if((needs).peek() != 'h') {
            while (needs >> rd) {
			  (roads[rd])->built(ToString(br));
            }
		}
		needs.clear();
	    needs.ignore();
		int addr;
		char resType;
		while (needs >> addr) {
			needs >> resType;
			#ifdef DEBUG
			cout << "Building " << resType << " at " << addr << endl;
			#endif
			if ((resType == 'B') || (resType == 'H') || (resType == 'T')) {
				createB(b[br], addr);
				#ifdef DEBUG
				cout << res[addr]->printRes() << endl;
				#endif


			} 
			if ((resType == 'H') || (resType == 'T'))  {
				res[addr] = make_shared<House>(res[addr]);

			}
			if  (resType == 'T')  {
				res[addr] = make_shared<Tower>(res[addr]);
			}
			#ifdef DEBUG
			//cout << res[addr]->printRes() << endl;
			#endif			
			if (needs.eof()) {
				#ifdef DEBUG
				cout << "ends" << endl;
				#endif
				break;
			}
		}
		
	}
	int tiletype;
	int value;
	for (int i = 0; i < numTiles; ++i) {
		*inp >> tiletype;
		*inp >> value;
		tiles[i] = (make_shared<Tile>(intToType(tiletype), i, value));
	}	   
}
		
		
		
			
		
void Board::print() const{
    int r = 1;
    int ad = 0;
    int rd = 0;
    int t = 0;
    for (r = r; r < 42; r++) {
        if ((r == 1) || (r == 41)) {
            cout << nspace(20);
            print1(&ad,&rd);
        } else if ((r == 2) || (r == 38) || (r == 40)) {
            cout << nspace(22) << "|" << nspace(width) << "|";
        } else if (r == 3) {
            cout << nspace(21);
            print3(&rd,t);
        } else if (r == 4) {
			cout << nspace(22);
            print4(t);
        } else if ((r == 5) || (r == 37)) {
            cout << nspace(10);
            print1(&ad,&rd);
            printTV(t);
            print1(&ad,&rd);
        } else if (r == 6) {
            cout << "            ";
            cout << "|         ";
            print2(&t);
            cout << "         |";
        } else if (r == 34) {
            cout << "            ";
            print2(&t);
            cout << "         ";
            print2(&t);
        } else if (r == 36) {
            cout << "            |         ";
            print4(t);
            cout << "         |";
        } else if (r == 7) {
            cout << nspace(11);
			print3(&rd,t);
            cout << nspace(8);
            print3(&rd,t+1);
		} else if (r == 35){
			cout << nspace(11) << (roads[rd])->printRoad() << nspace(8);
		    rd++;
            print3(&rd,t);
            cout << nspace(width-1);
            cout << (roads[rd])->printRoad();
			rd++;
        } else if (r == 8) {
			cout << nspace(12);
            print4(t);
			cout << nspace(9);
			print4(t+1);
        } else if (r == 39) {
            cout << nspace(21) << (roads[rd])->printRoad() << nspace(8);
            rd++;
            cout << (roads[rd])->printRoad();
            rd++;
        } else if (r % 8 == 1) {
            print1(&ad,&rd);
            printTV(t);
            print1(&ad,&rd);
            printTV(t+1);
            print1(&ad,&rd);
        } else if (r % 8 == 2) {
            cout << "  |         ";
            print2(&t);
            cout << "         ";
            print2(&t);
            cout << "         |";
        } else if (r % 8 == 6) {
            cout << "  ";
            print2(&t);
            cout << nspace(9);
            print2(&t);
            cout << nspace(9);
            print2(&t);
            
        } else if (r % 8 == 3) {
            cout << " ";
            print3(&rd,t);
            cout << nspace(width-1);
            print3(&rd,t+1);
            cout << nspace(width-1);
            print3(&rd,t+2);
        } else if (r % 8 == 4) {
			cout << nspace(2);
            print4(t);
            cout << nspace(width);
            print4(t+1);
            cout << nspace(width);
            print4(t+2);
        } else if (r % 8 ==5) {
            cout << (res[ad])->printRes();
            ad++;
            printTV(t);
            print1(&ad,&rd);
            printTV(t+1);
            print1(&ad,&rd);
            printTV(t+2);
            cout << (res[ad])->printRes();
            ad++;
        } else if (r % 8 == 7) {
            cout << nspace(1) << (roads[rd])->printRoad() << nspace(width-1);
            rd++;
            print3(&rd,t);
            cout << nspace(width-1);
            print3(&rd,t+1);
            cout << nspace(width-1);
            cout << (roads[rd])->printRoad() << nspace(width-1);
            rd++;
        } else {
            cout << "  |" << nspace(width);
            print4(t);
            cout << nspace(width);
            print4(t+1);
            cout << nspace(width) << "|";
        }
        cout << endl;
    }
}




void Board::tile_chosen(int n) {
    
    int i = 0;
    int j = 0;
	bool no_res_called = true;
    while (i < numTiles) {
        
      if (tiles[i]->getValue() == n) {

        if (tiles[i]->notify()) {
		    no_res_called = false;
	    }
        ++j;
      }
      ++i;
	}
    if ((j == 0) || (no_res_called)) {
		cout << "No builders gained resources." << endl;
	}
}



void Board::attach_to_tile(shared_ptr<Residence> r) {

  int i = 0;

  while (i < numTiles) {
	  int addr = r->getAddr();

    if ((tiles[i])->addr_on_tile(addr)) {

      tiles[i]->attach(r);

    }

    ++i;

  }

}

bool Board::pathAvailable(int address) {
  if ((getRoad(address))->getOwner() != "") {
    return false;
  }
  return true;
}

shared_ptr<Residence> Board::getRes(int address) {
   return res[address];

}

shared_ptr<Road> Board::getRoad(int address) {
  return roads[address];

}



void Board::buildRoad(int address, shared_ptr<Builder> b) {
  (getRoad(address))->built(b->getColor());
}


string Board::save() {

  string s = "";

  int i = 0;

  while (i < numTiles) {

    if (i != 0) {

      s += " ";

    }

    int j = tiles[i]->getTtype();
	string intj = to_string(j);
	s += intj;
	s += " ";
    int p =  tiles[i]->getValue();
	string intp = to_string(p);
    s += intp;
    ++i;
}

  return s;

}


void Board::dettach_from_tile(shared_ptr<Residence> r) {
    int addr = r->getAddr();
    int i = 0;
    while (i < numTiles) {
        if (tiles[i]->addr_on_tile(addr)) {
            tiles[i]->detach(r);
        }
        ++i;
    }
}


bool Board::geese_to_tile(int addr, string current) {
    return tiles[addr]->notify_geese(current);
}

void Board::setGeese(int g) {
    geese = g;
}

void Board::createB(shared_ptr<Builder> b, int n) {
	res[n] = make_shared<Basement>(b,res[n]);
}

void Board::improve(int n, char type) {
	if (type == 'B') {
		res[n] = make_shared<House>(res[n]);
	}
	else if (type == 'H') {
		res[n] = make_shared<Tower>(res[n]);
	}
}

































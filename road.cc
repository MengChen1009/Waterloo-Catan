#include "road.h"
#include <string>
using namespace std;

Road::Road(int addr): addr{addr} {
  owner = "";
}

void Road::built(string builder) {
  owner = builder;
}

string Road::getOwner() {
  return owner;
}

string Road::printRoad() {
  string s = "";
  if (owner != "") {
    s += owner[0];
    s += "R";
  } else {
    if (addr < 10) {
      s += " ";
    }
    s += to_string(addr);
  }
  return s;
}

int Road::getAddr() {
    return addr;
}


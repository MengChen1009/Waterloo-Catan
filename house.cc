#include "house.h"
#include <string>
#include <memory>

using namespace std;

House::House(shared_ptr<Residence> r): Decorator{r} {}

char House::getRtype() {
  return type;
}

int House::getAddr() {
  return r->getAddr();
}

std::string House::printRes() {
  string s = "|";
  s += (getOwner()->getColor())[0];
  s += type;
  s += "|";
  return s;
}

shared_ptr<Builder> House::getOwner() {
  return r->getOwner();
}

void House::notified(TileType t, int n) {
  getOwner()->notified(t, 2);
}


string House::notified_geese() {
    return getOwner()->getColor();
}

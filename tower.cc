#include "tower.h"
#include <string>
#include <memory>

using namespace std;

Tower::Tower(shared_ptr<Residence>): Decorator{r} {}

char Tower::getRtype() {
  return type;
}

int Tower::getAddr() {
  return r->getAddr();
}

std::string Tower::printRes() {
  string s = "|";
  s += (getOwner()->getColor())[0];
  s += type;
  s += "|";
  return s;
}

shared_ptr<Builder> Tower::getOwner() {
  return r->getOwner();
}

void Tower::notified(TileType t, int n) {
  getOwner()->notified(t, 3);
}

string Tower::notified_geese() {
    return getOwner()->getColor();
}

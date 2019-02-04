#include "basement.h"
#include <memory>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "builder.h"

using namespace std;

Basement::Basement(shared_ptr<Builder> owner, shared_ptr<Residence> r): owner{owner}, Decorator{r} {}

char Basement::getRtype() {
  return type;
}

int Basement::getAddr() {
  return r->getAddr();
}

shared_ptr<Builder> Basement::getOwner() {
  return owner;
}

std::string Basement::printRes() {
  string s = "|";
  s += (owner->getColor())[0];
  s += type;
  s += "|";
  return s;
}

void Basement::notified(TileType t, int n) {
  owner->notified(t, 1);
}

string Basement::notified_geese() {
    return owner->getColor();
}

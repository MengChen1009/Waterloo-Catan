#ifndef _HOUSE_H_
#define _HOUSE_H_
#include "decorator.h"
#include <string>
#include <memory>
#include <iostream>
#include "builder.h"

class House: public Decorator {
  char type = 'H';
  public:
  House(std::shared_ptr<Residence> r);
  char getRtype() override;
  int getAddr() override;
  std::string printRes() override;
  std::shared_ptr<Builder> getOwner() override;
  void notified(TileType t, int n) override;
  std::string notified_geese() override;
};

#endif

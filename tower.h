#ifndef __TOWER_H__
#define __TOWER_H__
#include "decorator.h"
#include "builder.h"
#include <string>
#include <memory>

class Tower: public Decorator {
  char type = 'T';
 public:
  Tower(std::shared_ptr<Residence>);
  char getRtype() override;
  int getAddr() override;
  std::string printRes() override;
  std::shared_ptr<Builder>getOwner() override;
  void notified(TileType t, int n) override;
  std::string notified_geese() override;
};

#endif


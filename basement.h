#ifndef _BASEMENT_H_
#define _BASEMENT_H_
#include "decorator.h"
#include <string>
#include <memory>
#include "builder.h"

class Basement: public Decorator {
  char type = 'B';
  std::shared_ptr<Builder> owner;
 public:
  Basement(std::shared_ptr<Builder> owner, std::shared_ptr<Residence> r);
  char getRtype() override;
  int getAddr() override;
  std::string printRes() override;
  std::shared_ptr<Builder> getOwner() override;
  void notified(TileType t, int n) override;
  std::string notified_geese() override;
};

#endif

#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "residence.h"
#include "observer.h"
#include <memory>

class Decorator: public Residence {
 protected:
  std::shared_ptr<Residence> r;

 public:
  Decorator(std::shared_ptr<Residence> r);
  virtual ~Decorator();
};

#endif

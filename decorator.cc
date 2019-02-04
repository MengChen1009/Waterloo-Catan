#include "decorator.h"
#include <memory>

Decorator::Decorator(std::shared_ptr<Residence> r): r{r} {}

Decorator::~Decorator() {}



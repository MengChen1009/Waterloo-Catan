//
//  Residence.hpp
//  Group projectçCtor
//
//  Created by ChenMeng on 3/28/17.
//  Copyright ¬© 2017 ChenMeng. All rights reserved.
//

#ifndef Residence_hpp
#define Residence_hpp
#include "observer.h"
#include <string>
#include <memory>
#include <iostream>

class Builder;

class Residence: public Observer {
public:
    virtual ~Residence()=0;
    virtual char getRtype()=0;
    virtual int getAddr()=0;
    virtual std::string printRes()=0;
    virtual std::shared_ptr<Builder> getOwner()=0;
};

#endif /* Residence_hpp */


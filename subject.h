//
//  Subject.hpp
//  Group project－Ctor
//
//  Created by ChenMeng on 3/28/17.
//  Copyright © 2017 ChenMeng. All rights reserved.
//

#ifndef Subject_hpp
#define Subject_hpp

#include <vector>
#include <memory>
#include <iostream>
#include "tiletype.h"

class Observer;

class Subject {
protected:
    std::vector<std::shared_ptr<Observer>> obslist;
public:
    virtual ~Subject()=0;
    virtual TileType getTtype() const = 0;
    bool notify();
    void attach(std::shared_ptr<Observer> o);
    void detach(std::shared_ptr<Observer> o);
    bool notify_geese(std::string current);
};

#endif /* Subject_hpp */

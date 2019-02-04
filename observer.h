//
//  Observer.hpp
//  Group project－Ctor
//
//  Created by ChenMeng on 3/28/17.
//  Copyright © 2017 ChenMeng. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include "tiletype.h"

class Subject;

class Observer {
public:
    virtual ~Observer()=0;
    virtual void notified(TileType t, int n);
    virtual std::string notified_geese();
};

#endif /* Observer_hpp */

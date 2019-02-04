//
//  EmptyResidence.hpp
//  Group project－Ctor
//
//  Created by ChenMeng on 3/28/17.
//  Copyright © 2017 ChenMeng. All rights reserved.
//

#ifndef EmptyResidence_hpp
#define EmptyResidence_hpp
 
#include "residence.h"
#include <string>
#include <memory>
#include <iostream>

class Empty: public Residence {
    int addr;
    char type = 'E';
public:
    Empty(int addr);
    int getAddr() override;
    char getRtype() override;
    std::string printRes() override;
    std::shared_ptr<Builder> getOwner() override;
};

#endif /* EmptyResidence_hpp */

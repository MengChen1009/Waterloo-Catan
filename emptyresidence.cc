//
//  EmptyResidence.cpp
//  Group project－Ctor
//
//  Created by ChenMeng on 3/28/17.
//  Copyright © 2017 ChenMeng. All rights reserved.
//

#include "emptyresidence.h"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

Empty::Empty(int addr):addr(addr) {}

int Empty::getAddr() {
    return addr;
}
    
char Empty::getRtype() {
    return type;
}

string Empty::printRes() {
    string s = "|";
    if (addr < 10) {
        s += " ";
    }
    s += to_string(addr);
    s += "|";
    return s;
}

shared_ptr<Builder> Empty::getOwner() {
  return nullptr;
}


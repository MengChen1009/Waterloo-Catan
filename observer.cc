//
//  Observer.cpp
//  Group project－Ctor
//
//  Created by ChenMeng on 3/28/17.
//  Copyright © 2017 ChenMeng. All rights reserved.
//

#include "observer.h"



Observer::~Observer() {}

void Observer::notified(TileType t, int n) {}

std::string Observer::notified_geese() {
	return "Nobody";
}

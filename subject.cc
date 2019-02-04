//
//  Subject.cpp
//  Group project－Ctor
//
//  Created by ChenMeng on 3/28/17.
//  Copyright © 2017 ChenMeng. All rights reserved.
//

#include "observer.h"
#include "subject.h"
#include <vector>
#include <memory>
#include <iostream>



using namespace std;

Subject::~Subject() {}

void Subject::attach(shared_ptr<Observer> o) {
  obslist.emplace_back(o);
}

bool Subject::notify() {
    int size = obslist.size();
    if (size == 0) {
        return false;
    }
    for (auto o : obslist) o->notified(getTtype(), 0);
	return true;
}


void Subject::detach(shared_ptr<Observer> o) {
    for (auto it = obslist.begin(); it != obslist.end(); ++it) {
        if (*it == o) {
            obslist.erase(it);
            break;
        }
    }
}

bool Subject::notify_geese(string current) {
    int i = 0;
    int size = obslist.size();
	if (size != 0) {
		cout << "Builder " << current << " can choose to steal from ";
	    vector<string> builders;
        while (i < size) {
		  bool exist = false;
          string s = obslist[i]->notified_geese();
		  int j = builders.size();
		  while (j > 0) {
			  if (builders[j-1] == s) { 
			  exist = true;
			  break; 
			  }
			--j;
		}
		if ((!exist) && (s != current)) {
			builders.emplace_back(s);
			cout << s;
			if (i != (size-1)) {
				cout << ",";
			} else {
				cout << ".";
			}
		}
        ++i;

	}
    cout << endl;
	cout << "Choose a builder to steal from." << endl;
	return true;
	} else {
		cout << "Builder " << current << " has no builders to steal from." << endl;
		return false;
	}
}

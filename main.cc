#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "residence.h"
#include "emptyresidence.h"
#include "tile.h"
#include "observer.h"
#include "subject.h"
#include "builder.h"
#include "board.h"
#include "decorator.h"
#include "basement.h"
#include "house.h"
#include "tower.h"
#include "color.h"
#include "road.h"
#include "tiletype.h"
#include "residencetype.h"
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit|ios::failbit);
    while (true) {
        
        string cmd;
        int n;
        vector<shared_ptr<Builder>> builderlist (4);
        builderlist[Blue] = make_shared<Builder> ("Blue");
        builderlist[Red] = make_shared<Builder> ("Red");
        builderlist[Orange] = make_shared<Builder> ("Orange");
        builderlist[Yellow] = make_shared<Builder> ("Yellow");
        shared_ptr<Builder> current;
        string dicetype;
        int dice = 0;
        string winner = "";
        bool IsGameStarted = false;
        Board b;
        string builder;
        
        
        //------------------------Command Line Argument---------------(create a Board)
        try {
            bool IsBoardCreated = false;
            int i_args = 1;
			if (argc == 1) throw 0;
            while(i_args < argc) {
                
                string input = argv[i_args];
                if( input == "seed" && !IsBoardCreated) {
                    int seed;
				    stringstream s_seed(argv[++i_args]);
                    s_seed >> seed;
                    b.setseed(seed);
                } else if (input == "board" && !IsBoardCreated) {
                    string filename = argv[++i_args];
                    auto ss_board = make_shared<ifstream>(filename);
                    b.makeboard(ss_board);
                    IsBoardCreated = true;
                } 
				else if (input == "load" && !IsBoardCreated) {
                    ifstream f_load(argv[++i_args]);
                    string load_info;
                    if(f_load.is_open()) {
                        getline(f_load, load_info);
                        if(load_info == "0") {
                            current = builderlist[0];
                        } else if (load_info == "1") {
                            current = builderlist[1];
                        } else if (load_info == "2") {
                            current = builderlist[2];
                        } else if (load_info == "3") {
                            current = builderlist[3];
                        }
                        getline(f_load, load_info);
                        builderlist[0]->set(load_info);
                        
                        getline(f_load, load_info);
                        builderlist[1]->set(load_info);
                        
                        getline(f_load, load_info);
                        builderlist[2]->set(load_info);
                        
                        getline(f_load, load_info);
                        builderlist[3]->set(load_info);
                    }
                    string filename = argv[i_args];
                    auto ss_load = make_shared<ifstream>(filename);
                    b.load(ss_load, builderlist);
                    IsBoardCreated = true;
                    IsGameStarted = true;
                } else if (input == "random-board" && !IsBoardCreated) {
                    b.init();
					IsBoardCreated = true;
					#ifdef DEBUG
					cout << "random-board is generated." << endl;
					#endif
                }
                ++i_args;
            }
        } catch (...) {
            cout << "Invalid command line arguments" << endl;
			abort();
            //exit the game
        }
        //-------------------------------------------------------
        
        
        //Starts playing
        
        while (true) {
            
            // Beginning of Game
            if(!IsGameStarted) {
                int i = 0;
                string builder = "Blue";
                while (i < 8) {
                    if ((i == 0) || (i == 7)) {
                        builder = "Blue";
                        current = builderlist[Blue];
                    } else if ((i == 1) || (i == 6)) {
                        builder = "Red";
                        current= builderlist[Red];
                    } else if ((i == 2) || (i == 5)) {
                        builder = "Orange";
                        current= builderlist[Orange];
                    } else if ((i == 3) || (i == 4)) {
                        builder = "Yellow";
                        current= builderlist[Yellow];
                    }
                    cout << "Builder " << builder <<
                    ", where do you want to build a basement?" << endl;
						cin >> n; // address
					
	
                    if ((n >= 0) && (n <= 53) && (b.addrAvailable(n)) ) { //valid address
                        b.createB(current, n);
                        b.attach_to_tile(b.getRes(n));
						current->resbuilt(n);
						++i;
					} else if ((n < 0) || (n > 53))  {
						cout << "Invalid command." << endl;
					} else if (cin.fail()) {
						cout << "Invalid command." << endl;
						cin.clear();
						cin.ignore();
                    } else {
                        cout << "You cannot build here." << endl;
                    }
					
                }
                current = builderlist[0];
            }
            
            // Builder's Turn
            builder = current->getColor();
            while (true) {
                cout << "Builder " << builder << "'s turn." << endl;
                builderlist[0]->printStatus();
				builderlist[1]->printStatus();
				builderlist[2]->printStatus();
				builderlist[3]->printStatus();
                
                while (true) { // Beginning of Turn
                    cin >> cmd; // valid commands: load/fair/roll
                    if (cmd == "load") {
                        dicetype = "load";
                    }
                    else if (cmd == "fair") {
                        dicetype = "fair";
                    }
                    else if (cmd == "roll") {
                        if (dicetype == "load") {
                            cout << "Input a roll between 2 and 12:" << endl;
                            while (true) {
							 cin >> dice;
                             if ((dice < 2) || (dice > 12)) {
                                cout << "Invalid roll." << endl;
							 } else { break;}
							}
                        }
                        else if (dicetype == "fair") {
                            int i = rand() % 6 + 1;
                            int j = rand() % 6 + 1;
                            dice = i + j;
                        }
						if (dice != 7) {
							b.tile_chosen(dice);
						} else if (dice == 7) { // moving geese;
                            int k = 0;
                            while (k < 4) {
                                int numr = builderlist[k]->numResource();
                                if (numr >= 10) {
                                    int to_geese = numr / 2;
                                    cout << "Builder " << builderlist[k]->getColor() << " loses " <<
                                    to_geese << " resources to the geese. They lose:" << endl;
                                    while (to_geese > 0) {
                                        int j = rand() % 4 + 0;
                                        while (builderlist[k]->hasResource(j)) {
                                            builderlist[k]->loseResource(j);
                                            --to_geese;
                                            if (to_geese == 0) { break; }
                                        }
                                        int lost = 5 - to_geese;
                                        if (lost > 0) {
                                            TileType t = static_cast<TileType>(j);
                                            cout << lost << " " << t << endl;
                                        }
                                    }
                                }
                                ++k;
                            }
                            cout << "Choose where to place the GEESE." << endl;
                            int i;
                            cin >> i;
                            b.setGeese(i);
							string t = current->getColor();
                            if (b.geese_to_tile(i, t)) {
                            string s;
                            cin >> s;
							srand(time(NULL));
							Color c = ToColor(s);
                            if (builderlist[c]->numResource() != 0) {
                              while (true) {
                                  int j = rand() % 4 + 0;
                                  if (builderlist[c]->hasResource(j)) {
                                      current->gainResource(j);
                                      builderlist[c]->loseResource(j);
                                      TileType t = static_cast<TileType>(j);
                                      cout << "Builder " << builder << " steals " << t
                                      << " from builder " << s << "." << endl;
                                      break;
                                  }    
                              }
							} else {
								cout << "Builder " << s << " does not have any resources." << endl;
							}
							}
                        }
                        break;
                    } else {
                        cout << "Invalid command." << endl;
						cin.clear();
						cin.ignore();
                    }
                }
                
                // During the Turn
                while (true) {
                    cin >> cmd; // valid commands: board/status/residences/build-road/build-res/improve/trade/next/save/help
                    if (cmd == "board") {
                        b.print();
                    } else if (cmd == "status") {
                        current->printStatus();
                    } else if (cmd == "residences") {
                        current->printBuildings();
                    } else if (cmd == "build-road") {
                        cin >> n; // road#
                        if (b.pathAvailable(n)) { // nobody else has built a road on n;
                            if (current->buildroad(n)) { // has enough energy and built ajacent road/res;
                                (b.getRoad(n))->built(current->getColor()); // change owner of road on n on board
                            }
                        } else {
                          cout << "You cannot build here." << endl;
                        }
                    } else if (cmd == "build-res") {
                        cin >> n; // housing#
                        if (b.addrAvailable(n)) { // nobody else has built a res on n;
                            if (current->buildres(n)) { // has enough energy and built ajacent road/res;
                                b.createB(current, n);
                                b.attach_to_tile(b.getRes(n));
                            } 
						} else {
                          cout << "You cannot build here." << endl;
						}
                    } else if (cmd == "improve") {
                        cin >> n; //housing#
                        if (current->improve(n)) {
							char type = (b.getRes(n))->getRtype();
                            if (type == 'B') {
								b.dettach_from_tile(b.getRes(n));
                                b.improve(n, 'B');
                                b.attach_to_tile(b.getRes(n));
                            } else if (type == 'H') {
								b.dettach_from_tile(b.getRes(n));
                                b.improve(n, 'H');
                                b.attach_to_tile(b.getRes(n));
                            }
                        }
                    } else if (cmd == "trade") {
                        string color,give,take;
                        cin >> color >> give >> take;
						cout << current->getColor() << " offers " << color << " one " << give << " for one " << take << endl;
                        cout << "Does " << color << " accept this offer?" << endl;
						string s;
						cin >> s;
						if (s == "yes" ) {
	
                        current->trade(give, take, builderlist[ToColor(color)]);
						}
                    } else if (cmd == "next") {
                        if (current->getPts() == 10) {
                            winner = current->getColor();
                        }
                        if (builder == "Blue") {
                            builder = "Red";
                            current = builderlist[Red];
                        } else if (builder == "Red") {
                            builder = "Orange";
                            current = builderlist[Orange];
                        } else if (builder == "Orange") {
                            builder = "Yellow";
                            current = builderlist[Yellow];
                        } else if (builder == "Yellow") {
                            builder = "Blue";
                            current = builderlist[Blue];
                        }
                        break;
                    } else if (cmd == "save") {
                        string file;
                        cin >> file;
                        string builder0Data = builderlist[Blue]->save();
                        string builder1Data = builderlist[Red]->save();
                        string builder2Data = builderlist[Orange]->save();
                        string builder3Data = builderlist[Yellow]->save();
                        string boardData = b.save();
						ofstream fileout;
						fileout.open(file);
						int turn = ToColor(current->getColor());
						fileout << turn << "\n";
						fileout << builder0Data << "\n";
						fileout << builder1Data << "\n";
						fileout << builder2Data << "\n";
						fileout << builder3Data << "\n";
						fileout << boardData;
						fileout.close();
						
                    } else if (cmd == "help") {
                        cout << "Valid commands:" << endl;
                        cout << "board\nstatus\nresidences" << endl;
                        cout << "build-road <path#>\nbuild-res <housing#>" << endl;
                        cout << "improve <housing#>\ntrade <colour> <give> <take>\nnext\nsave <file>\nhelp" << endl;
                    } else {
                        cout <<"Invalid command." << endl;
                    }
                }
                if (winner != "") break;
            }
            if (winner != "") break;
        }
        
        // End of Game
        if (winner != "") {
            cout << "The winner is " << winner << "." << endl;
            cout << "Would you like to play again?" << endl;
            cin >> cmd; // valid commands: yes/no;
            if (cmd == "yes") {
                int j = 0;
                while (j < 4) {
                    builderlist[j].reset();
                    ++j;
                }
            } else if (cmd == "no") {
                break;
            } else {
                cout <<"Invalid command." << endl;
            }
        }
    }
}


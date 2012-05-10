#ifndef MAIN_H_
#define MAIN_H_

#include <libplayerc++/playerc++.h>
#include <pthread.h>
#include <cmath>
#include <iostream>
#include <string>
#include "KinectARNav.h"

PlayerCc::PlayerClient* robot;
PlayerCc::Position2dProxy* pp;

KinectARNav* knav;

string hostname = "localhost";
int port = 6665;
bool quitting = false;
string cli_line;

#endif /* MAIN_H_ */

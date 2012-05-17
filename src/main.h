#ifndef MAIN_H_
#define MAIN_H_

#include <pthread.h>
#include <cmath>
#include <iostream>
#include <string>
#include <libplayerc++/playerc++.h>
#include "KinectARNav.h"

PlayerCc::PlayerClient* robot;
PlayerCc::Position2dProxy* pp;

KinectARNav* knav;

std::string usage_instructions = "Usage: ./Kinect-AR-Nav [[hostname] [port]] [config_filename]";
std::string hostname = "localhost";
std::string config_fname = "../../config/sample.json"; // relative to build/src/ in project directory
std::string cli_line;

double speed;
double turnrate;

int port = 6665;

bool navigating = false;
bool running_realtime = true;
bool quitting = false;

void* realtime_control(void*);

#endif /* MAIN_H_ */

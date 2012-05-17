/*
 * KinectARNav library demo program
 *
 * Written by Andrew Stebbins
 */

#include "main.h"

using namespace PlayerCc;
using namespace std;

void* realtime_control(void* arg)
{
	while(running_realtime)
        {
                robot->Read();

                speed = 0.0;
                turnrate = 0.0;

		if(navigating)
		{
			// TODO: after non-blocking check on whether KinectARNav is ready (must
			// block as Create data must be de-buffered at a minimum of 10Hz), read
			// speed and turnrate values

			// TODO: also do last-minute object avoidance with Brobot (specific RIT robot platform)'s sonar?
		}

                pp->SetSpeed(speed, turnrate);
        }

	// TODO: set flag to indicate realtime control thread has shutdown cleanly

        pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	cout << "Hello robot world!" << endl;
	
	speed = 0.0;
	turnrate = 0.0;
	navigating = false;

	// process command line args
	if(argc == 1 || argc == 2 || argc == 4)
	{
		if(argc > 1)
		{
			int pos = 1;

			if(argc == 4)
			{
				hostname = argv[pos];
				port = atoi(argv[pos+1]);			
				pos += 2;
			}
			
			config_filename = argv[pos];
		}
	} 
	else
	{
		// print usage instructions and exit
		cout << usage_instructions << endl;
		return 0;
	}

	// initialize PlayerClient and position proxy
	robot = new PlayerClient(hostname, port);
	pp = new Position2dProxy(robot, 0);

	// initialize and start KinectARNav library
	KinectARNav knav();
	knav.init(config_filename, pp, true);	

	// start real-time robot control thread
	pthread_t realtime_control_thread;
        pthread_create( &realtime_control_thread, NULL, realtime_control, NULL );

	// TODO: enter basic control shell for KinectARNav library
	while(!quitting)
	{
		cout << ">> ";
		getline(cin, cli_line);

		if(cli_line.compare("quit") == 0 || cli_line.compare("exit") == 0)
		{
			quitting = true;
		}
		else if(cli_line.compare("stop") == 0)
		{
			navigating = false;
		}
		else if(li_line.compare("waypoints") == 0)
		{
			vector<string> waypoint_names = knav.getWaypoints();

			for(int k = 0; k < waypoint_names.size(); k++)
			{
				cout << "Waypoint " << k << ": " << waypoint_names[k] << endl;
			}
		}
		else
		{
			// TODO: tokenize and parse goto-command
			string command = "goto-id";

			// TODO: tokenize and parse goto-command arg
			if(command.compare("goto") == 0)
			{	
				navigating = true;
				string new_goal_name = "";
				knav.setGoalWaypointByName(new_goal_name);
				cout << "Navigating to new goal waypoint, name = " << new_goal_name << endl;
			}
			else if(command..compare("goto-id") == 0)
			{
				navigating = true;
				int new_goal_id = 0;
				knav.setGoalWaypointById(new_goal_id);
				cout << "Navigating to new goal waypoint, name = " << new_goal_id << endl;
			}
		}
	}

	// TODO: wait for realtime control thread to fully halt before stopping knav
	knav->shutdown();

	// TODO: correctly halt/free Player stuff also

	pthread_exit(NULL);

	return 0;	
}

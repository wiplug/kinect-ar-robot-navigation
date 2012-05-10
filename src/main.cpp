#include "main.h"

using namespace PlayerCc;
using namespace std;

int main()
{
	cout << "Hello robot world!" << endl;
	
	// TODO: process command line args and initialize PlayerClient
	robot = new PlayerClient(hostname, port);

	// TODO: initialize KinectARNav library instance
	//knav = new KinectARNav(conf_filename, pp, map_img_filename, int pop_siz);
	knav = new KinectARNav("", pp, NULL, 10000);

	// TODO: enter basic control shell for KinectARNav library
	while(!quitting)
	{
		cout << ">> ";
		cin >> cli_line;

		if(cli_line.compare("quit") == 0 || cli_line.compare("exit") == 0)
		{
			quitting = true;
		}
	}

	knav->shutdown();
	//delete knav;
	delete pp;

	return 0;
}

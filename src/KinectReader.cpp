#include "KinectReader.h"

KinectReader::KinectReader()
{
	requested_format = FREENECT_VIDEO_RGB;
        current_format = FREENECT_VIDEO_RGB;

	kinect_rgb_frame = Mat(480, 640, CV_8UC3);
        kinect_depth_frame = Mat(480, 640, CV_8UC1);
}

void KinectReader::run()
{

}

void* KinectReader::thread_main(void* arg)
{
	if (freenect_init(&f_ctx, NULL) < 0) {
                cout << "freenect_init() failed" << endl;
                pthread_exit(NULL);
        }

        freenect_set_log_level(f_ctx, FREENECT_LOG_DEBUG);
        freenect_select_subdevices(f_ctx, (freenect_device_flags)(FREENECT_DEVICE_MOTOR | FREENECT_DEVICE_CAMERA));

	int nr_devices = freenect_num_devices (f_ctx);
        cout << "Number of devices found: " << nr_devices << endl;

        int user_device_number = 0;

	if (nr_devices < 1) {
                freenect_shutdown(f_ctx);
                pthread_exit(NULL);
        }

        if (freenect_open_device(f_ctx, &f_dev, user_device_number) < 0) {
                cout << "Could not open device" << endl;
                freenect_shutdown(f_ctx);
                pthread_exit(NULL);
        }

	// TODO: loop until signaled to stop; populate RGBD buffer(s) in thread-safe manner

	pthread_exit(NULL);
}

void KinectReader::shutdown()
{}

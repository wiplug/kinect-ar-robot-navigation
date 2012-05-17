#include "KinectReader.h"

KinectReader::KinectReader()
{
	kinect_rgb_frame = Mat(480, 640, CV_8UC3);
        kinect_depth_frame = Mat(480, 640, CV_8UC1);
}

void KinectReader::run()
{

}

void* KinectReader::thread_main(void* arg)
{
	if (freenect_init(&f_ctx, NULL) < 0) {
                printf("freenect_init() failed\n");
                return 1;
        }

        freenect_set_log_level(f_ctx, FREENECT_LOG_DEBUG);
        freenect_select_subdevices(f_ctx, (freenect_device_flags)(FREENECT_DEVICE_MOTOR | FREENECT_DEVICE_CAMERA));

	if (nr_devices < 1) {
                freenect_shutdown(f_ctx);
                return 1;
        }

        if (freenect_open_device(f_ctx, &f_dev, user_device_number) < 0) {
                printf("Could not open device\n");
                freenect_shutdown(f_ctx);
                return 1;
        }

	// TODO: loop until signaled to stop; populate RGBD buffer(s) in thread-safe manner
}

void KinectReader::shutdown()
{}

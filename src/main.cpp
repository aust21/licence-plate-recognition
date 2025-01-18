#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;

int main()
{
    // Open the video stream
    cv::namedWindow("MyWindow", cv::WINDOW_NORMAL);
    cv::resizeWindow("MyWindow", 800, 600);

    cv::VideoCapture cap(liveFeedUrl, cv::CAP_FFMPEG);

    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open the video stream." << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        // Capture frame-by-frame
        cap >> frame;
        if (frame.empty())
            break;

        // Display the resulting frame
        cv::imshow("MyWindow", frame);

        // Press 'q' to exit
        if (cv::waitKey(30) == 'q')
            break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}

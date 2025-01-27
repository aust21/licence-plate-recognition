#include "base.h"

#include <array>
#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>
#include <string>

cv::CascadeClassifier loadCascade(std::string filepath)
{
    cv::CascadeClassifier plate_cascade;
    std::string full_path = std::string(RESOURCE_DIR) + "/" + filepath;
    if (!plate_cascade.load(full_path)) {
        throw std::runtime_error("Failed to load cascade classifier");
    }

    return plate_cascade;
}

cv::VideoCapture loadCam(std::string filepath)
{
    std::string full_path = std::string(RESOURCE_DIR) + "/" + filepath;
    cv::VideoCapture cap(full_path, cv::CAP_FFMPEG);

    if (!cap.isOpened()) {
        throw std::runtime_error("Failed to open video stream");
    }

    return cap;
}

int Base::run()
{
    try {
        cv::namedWindow("Licence plate detector", cv::WINDOW_NORMAL);
        cv::resizeWindow("Licence plate detector", 800, 600);

        // Open the video stream
        cv::VideoCapture cap = loadCam("cars2.mp4");

        cv::CascadeClassifier plate_cascade = loadCascade("plate_number.xml");

        cv::Mat frame, gray_frame;
        while (true) {
            cap >> frame;

            if (frame.empty()) {
                std::cout << "Empty frame received" << std::endl;
                break;
            }

            cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);

            // detect number plate
            std::vector<cv::Rect> plates;
            plate_cascade.detectMultiScale(gray_frame, plates, 1.2, 4, 0, cv::Size(60, 20));

            // Draw rectangles around detected plates
            for (const auto &plate : plates) {
                cv::rectangle(frame, plate, cv::Scalar(0, 255, 0), 2);
            }

            cv::imshow("Licence plate detector", frame);

            // Break the loop if 'q' is pressed
            char c = (char) cv::waitKey(1);
            if (c == 'q' || c == 'Q') {
                break;
            }
        }

        // Cleanup
        cap.release();
        cv::destroyAllWindows();

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}

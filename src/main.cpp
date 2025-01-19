#include <array>
#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>
#include <string>

std::string getStreamUrl(const std::string &youtubeUrl)
{
    std::array<char, 128> buffer;
    std::string result;

    // Construct yt-dlp command to get the direct stream URL
    std::string cmd = "yt-dlp -f \"best[height<=720]\" -g \"" + youtubeUrl + "\"";

    // Open pipe to command
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Read the command output
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    // Remove trailing newline if present
    if (!result.empty() && result[result.length() - 1] == '\n') {
        result.erase(result.length() - 1);
    }

    return result;
}

int main()
{
    try {
        // YouTube URL
        std::string youtubeUrl = "https://www.youtube.com/watch?v=uhIqvcQuvCs";

        // Get the direct stream URL
        std::string streamUrl = getStreamUrl(youtubeUrl);
        std::cout << "Retrieved stream URL" << std::endl;

        // Create window
        cv::namedWindow("YouTube Stream", cv::WINDOW_NORMAL);
        cv::resizeWindow("YouTube Stream", 800, 600);

        // Open the video stream
        cv::VideoCapture cap(streamUrl, cv::CAP_FFMPEG);
        if (!cap.isOpened()) {
            throw std::runtime_error("Failed to open video stream");
        }

        cv::Mat frame;
        while (true) {
            // Capture frame-by-frame
            cap >> frame;

            if (frame.empty()) {
                std::cout << "Empty frame received" << std::endl;
                break;
            }

            // Display the frame
            cv::imshow("YouTube Stream", frame);

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

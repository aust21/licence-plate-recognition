#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;

int main()
{
    std::string liveFeedUrl
        = "https://manifest.googlevideo.com/api/manifest/hls_playlist/expire/1737241899/ei/"
          "y-CLZ9m_F5jdp-oPn6_SiQo/ip/41.13.11.124/id/uhIqvcQuvCs.1/itag/96/source/"
          "yt_live_broadcast/requiressl/yes/ratebypass/yes/live/1/sgoap/gir%3Dyes%3Bitag%3D140/"
          "sgovp/gir%3Dyes%3Bitag%3D137/rqh/1/hdlc/1/hls_chunk_host/"
          "rr3---sn-8vq5jvh15-wocl.googlevideo.com/xpc/EgVo2aDSNQ%3D%3D/playlist_duration/30/"
          "manifest_duration/30/bui/"
          "AY2Et-PrtY3f2Sd5yK032tKzsBUJrg7LCfj_S16OHigYwDWSOyYaC3RFonSFBjCbF6m4gHgKybMuDKdx/spc/"
          "9kzgDUtK8lB1TvUM5ZrcGO1ctWRNiJZLs-cnQVeIdOiVZIlU00dc5Jnx8pq90nQRZQJsz60/vprv/1/"
          "playlist_type/DVR/initcwndbps/495000/met/1737220302,/mh/uT/mm/44/mn/sn-8vq5jvh15-wocl/"
          "ms/lva/mv/m/mvi/3/pl/18/rms/lva,lva/dover/11/pacing/0/keepalive/yes/fexp/"
          "51326932,51335594,51353498,51355912,51371294,51384461/mt/1737219875/sparams/"
          "expire,ei,ip,id,itag,source,requiressl,ratebypass,live,sgoap,sgovp,rqh,hdlc,xpc,"
          "playlist_duration,manifest_duration,bui,spc,vprv,playlist_type/sig/"
          "AJfQdSswRQIhAPDoZiO6rhc8n8kPuwe1RLeEH_ms-1B6JkMqzqCjyDuRAiBaiCm2m6vkBhdrvhPwxmQ01-"
          "u8WG4BY9Kp2ryXwa3lyQ%3D%3D/lsparams/"
          "hls_chunk_host,initcwndbps,met,mh,mm,mn,ms,mv,mvi,pl,rms/lsig/"
          "AGluJ3MwRQIgNVu3ZH4YPyEkYD8LsZBSq5PPRcNpe521GcAy7q-bGg0CIQCLYO_g3q4Ffa4_"
          "f6BlcM7h1h68oH6Dew7glt9r7dK7Jg%3D%3D/playlist/index.m3u8";
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

#include <iostream>
#include <opencv2\opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
    int a = 0;
    Mat img;
    VideoCapture capture(0);
    if (!capture.isOpened()) {
        std::cerr << "Could not open camera" << std::endl;
        return -1;
    }

    namedWindow("webcam", 1);
    CascadeClassifier face_classifier;

    face_classifier.load("C:/opencv/opencv-4.5.0/opencv-4.5.0/data/haarcascades/haarcascade_frontalface_default.xml");

    Mat frame;

    while (1) {
        bool frame_valid = true;

        try {
            // get a new frame from webcam
            capture >> frame;
        }
        catch (Exception& e) {
            cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;
            frame_valid = false;
        }

        if (frame_valid) {
            try {
                Mat grayframe;
                cv::cvtColor(frame, grayframe, COLOR_BGR2GRAY);
                equalizeHist(grayframe, grayframe);
                vector<Rect> faces;

                face_classifier.detectMultiScale(grayframe, faces, 1.1, 3, CASCADE_FIND_BIGGEST_OBJECT | CASCADE_SCALE_IMAGE, Size(30, 30)
                                    
                    
                );

                for (int i = 0; i < faces.size(); i++) {
                    Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
                    Point tr(faces[i].x, faces[i].y);
                    rectangle(frame, lb, tr, Scalar(0, 255, 0), 3, 4, 0);
                }
                imshow("webcam", frame);
            }

            catch (Exception& e) {
                cerr << "Exception occurred. Ignoring frame... " << e.err << std::endl;
            }
        }
        if (waitKey(30) >= 0) break;
    }
    return 0;
}
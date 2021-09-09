#include "opencv2/opencv.hpp"
#include <opencv2/highgui.hpp>
#include <vector>

int main(int args, char *argv[])
{
    cv::VideoCapture cap(0);

    if (!cap.isOpened())
    {
        return -1;
    }

    cv::CascadeClassifier cascade;
    cascade.load("./data/haarcascade_frontalface_default.xml");

    cv::Mat frame;
    while (1)
    {
        cap >> frame;
        std::vector<cv::Rect> faces;
        cascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(20, 20));
        for (int i = 0; i < faces.size(); i++)
        {
            cv::rectangle(frame, cv::Point(faces[i].x, faces[i].y), cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), cv::Scalar(0, 0, 255), 3, 16);
        }
        cv::imshow("win", frame);
        const int key = cv::waitKey(1);
        if (key == 'q')
        {
            break;
        }
        else if (key == 's')
        {
            cv::imwrite("img.png", frame);
        }
    }
    cv::destroyAllWindows();
    return 0;
}

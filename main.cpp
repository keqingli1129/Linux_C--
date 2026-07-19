#include <iostream>
#include <Eigen/Dense>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include "StaticLib/StaticLib.h"
#include "DynamicLib/DynamicLib.h"
int main(int, char**){
    std::cout << "Hello, from Linux_C++!\n";
    std::cout << StaticLib::greet("Alice") << std::endl;
    std::cout << "Factorial of 5: " << StaticLib::factorial(5) << std::endl;
    std::cout << "Addition of 3 and 4: " << DynamicLib::add(3, 4) << std::endl;
    std::cout << "Multiplication of 3 and 4: " << DynamicLib::multiply(3, 4) << std::endl;

    // Eigen sample
    Eigen::Matrix3f A;
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 10;

    Eigen::Vector3f b(3, 3, 4);
    Eigen::Vector3f x = A.colPivHouseholderQr().solve(b);

    std::cout << "\n--- Eigen Demo ---\n";
    std::cout << "Matrix A:\n" << A << "\n\n";
    std::cout << "Vector b:\n" << b.transpose() << "\n\n";
    std::cout << "Solution x (Ax = b):\n" << x.transpose() << "\n\n";
    std::cout << "Determinant of A: " << A.determinant() << "\n";
    std::cout << "Inverse of A:\n" << A.inverse() << "\n";

    // OpenCV sample
    std::cout << "\n--- OpenCV Demo ---\n";
    std::cout << "OpenCV version: " << CV_VERSION << "\n";

    cv::Mat img = cv::Mat::zeros(256, 256, CV_8UC3);
    cv::circle(img, cv::Point(128, 128), 80, cv::Scalar(0, 255, 0), 2);
    cv::rectangle(img, cv::Point(48, 48), cv::Point(208, 208), cv::Scalar(255, 0, 0), 2);
    cv::line(img, cv::Point(0, 0), cv::Point(255, 255), cv::Scalar(0, 0, 255), 1);

    std::cout << "Created 256x256 image with shapes\n";
    std::cout << "Image size: " << img.cols << "x" << img.rows << "\n";
    std::cout << "Channels: " << img.channels() << "\n";
    std::cout << "Type: CV_8UC3\n";

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    std::cout << "Converted to grayscale: " << gray.channels() << " channel(s)\n";

    cv::Mat blurred;
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 1.5);
    std::cout << "Applied Gaussian blur (5x5, sigma=1.5)\n";

    // Save images to files
    cv::imwrite("shapes.png", img);
    cv::imwrite("grayscale.png", gray);
    cv::imwrite("blurred.png", blurred);
    std::cout << "Saved shapes.png, grayscale.png, blurred.png\n";

    // Display images (requires display access)
    try {
        cv::namedWindow("Shapes", cv::WINDOW_AUTOSIZE);
        cv::namedWindow("Grayscale", cv::WINDOW_AUTOSIZE);
        cv::namedWindow("Blurred", cv::WINDOW_AUTOSIZE);
        cv::imshow("Shapes", img);
        cv::imshow("Grayscale", gray);
        cv::imshow("Blurred", blurred);
        std::cout << "Displaying images. Press any key to continue...\n";
        cv::waitKey(0);
        cv::destroyAllWindows();
    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV GUI error: " << e.what() << "\n";
        std::cerr << "Images were saved to disk instead.\n";
    }

    // USB Camera capture
    std::cout << "\n--- USB Camera Demo ---\n";
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open USB camera (device 0)\n";
        return 1;
    }

    std::cout << "Camera opened. Press 'q' to quit.\n";
    std::cout << "Resolution: " << cap.get(cv::CAP_PROP_FRAME_WIDTH) << "x"
              << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << "\n";

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Error: Empty frame\n";
            break;
        }
        cv::imshow("USB Camera", frame);
        if (cv::waitKey(1) == 'q')
            break;
    }
    cap.release();
    cv::destroyAllWindows();
}

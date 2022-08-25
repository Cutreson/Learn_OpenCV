//Cân bằng histogram ảnh xám
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat src = imread("D:/Learn_OpenCV/Basic/image.jpg", IMREAD_COLOR);
	Mat hsv, disp;
	cvtColor(src, hsv, COLOR_BGR2HSV);
	vector<Mat> hsv_channels;
	//Tach hsv thanh 3 kenh mau
	split(hsv, hsv_channels);
	//Can bang histogram kenh mau v
	equalizeHist(hsv_channels[1], hsv_channels[1]);
	//Tron anh
	merge(hsv_channels, hsv);
	//Chuyen sang rgb
	cvtColor(hsv, disp, COLOR_HSV2BGR);
	imshow("src", src);
	imshow("dst", disp);
	waitKey(0);
	return 0;

}

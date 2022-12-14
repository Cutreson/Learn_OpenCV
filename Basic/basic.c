//Load image
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	cout << "Hello" << endl;
	Mat img = imread("D:/Learn_OpenCV/Basic/image.jpg");
	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

//Đổi hệ màu
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat scr = imread("D:/Learn_OpenCV/Basic/image.jpg");
	Mat gray, hsv, ycrcb;
	cvtColor(scr, gray, COLOR_BGR2GRAY);
	cvtColor(scr, hsv, COLOR_BGR2HSV);
	cvtColor(scr, ycrcb, COLOR_BGR2YCrCb);
	imshow("scr", scr);
	imshow("gray", gray);
	imshow("hsv", hsv);
	imshow("ycrcb", ycrcb);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

//Điều chỉnh độ sáng
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat scr = imread("D:/Learn_OpenCV/Basic/image.jpg");
	Mat dst = scr.clone();
	double alpha = 3;
	int beta = 30;
	for(int i = 0; i < scr.rows; i++)
		for(int j = 0; j < scr.cols; j++)
			for (int k = 0; k < 3; k++)
			{
				dst.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(alpha * (scr.at<Vec3b>(i, j)[k]) + beta);
			}
	imshow("old", scr);
	imshow("new", dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

//Ảnh nhị phân
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat scr = imread("D:/Learn_OpenCV/Basic/image.jpg");
	Mat gray, dst;
	cvtColor(scr, gray, COLOR_RGB2GRAY);
	threshold(gray, dst, 100, 255, THRESH_BINARY);
	imshow("old", scr);
	imshow("gray", gray);
	imshow("new", dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

//Ảnh nhị phân hóa ngưỡng động
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat scr = imread("D:/Learn_OpenCV/Basic/image.jpg");
	Mat gray, dst;
	cvtColor(scr, gray, COLOR_RGB2GRAY);
	adaptiveThreshold(gray, dst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 35, 5);
	imshow("old", scr);
	imshow("gray", gray);
	imshow("new", dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

//Histogram
//#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat src = imread("D:/Learn_OpenCV/Basic/image.jpg");
	vector<Mat> img_rgb;
	Mat img_r, img_g, img_b;

	int w = 400, h = 400;
	int size_hist = 225;
	float range[] = { 0, 255 };
	const float* hist_range = { range };

	split(src, img_rgb);
	calcHist(&img_rgb[0], 1, 0, Mat(), img_b, 1, &size_hist, &hist_range, true, false);
	calcHist(&img_rgb[1], 1, 0, Mat(), img_g, 1, &size_hist, &hist_range, true, false);
	calcHist(&img_rgb[2], 1, 0, Mat(), img_r, 1, &size_hist, &hist_range, true, false);

	int bin = cvRound((double)w / size_hist);

	Mat disp_r(w, h, CV_8UC3, Scalar(255, 255, 255));
	Mat disp_g = disp_r.clone();
	Mat disp_b = disp_r.clone();

	normalize(img_b, img_r, 0, disp_b.rows, NORM_MINMAX, -1, Mat());
	normalize(img_g, img_g, 0, disp_g.rows, NORM_MINMAX, -1, Mat());
	normalize(img_r, img_b, 0, disp_r.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < 255; i++)
	{
		line(disp_r, Point(bin * (i), h), Point(bin * (i), h - cvRound(img_r.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
		line(disp_g, Point(bin * (i), h), Point(bin * (i), h - cvRound(img_g.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(disp_b, Point(bin * (i), h), Point(bin * (i), h - cvRound(img_b.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
	}
	namedWindow("src", 0);
	imshow("src", src);
	imshow("Histogram of Blue chennel", disp_b);
	imshow("Histogram of Green chennel", disp_g);
	imshow("Histogram of Red chennel", disp_r);
	waitKey(0);
	return 0;

}

//Cân bằng histogram ảnh xám
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat src = imread("D:/Learn_OpenCV/Basic/image.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	equalizeHist(src, dst);
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;

}
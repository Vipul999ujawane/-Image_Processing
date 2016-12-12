#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

	//namedWindow("Double", WINDOW_AUTOSIZE);
	//createTrackbar("Cols", "Double", &cols, 100);
	Mat a = imread("len_top.jpg", 0);
	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));
	int intensity[256];
	for (int i = 0; i < 256; i++)
	{
		intensity[i] = 0;
	}
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
		{
			intensity[a.at<uchar>(i, j)] += 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < 256; i++)
	{
		sum += intensity[i];
	}
	int threshold = 0;
	int sum2 = 0;
	while ((sum2) < (sum / 2))
	{
		sum2 += intensity[threshold];
		threshold++;
	}
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
		{
			if (a.at<uchar>(i, j)>threshold)
			{
				b.at<uchar>(i, j) = 255;
			}
			else
			{
				b.at<uchar>(i, j) = 0;
			}
		}
	}
	imshow("Trump", a);
	imshow("Donald", b);
	waitKey(0);
	return 0;
}

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a = imread("Ex1.png", 0);
	Mat apple(a.rows, a.cols, CV_8UC1, Scalar(0));
	int v = 127;
	namedWindow("Gray", WINDOW_AUTOSIZE);
	createTrackbar("TrackBar", "Gray", &v, 255);
	while (1)
	{
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				if (a.at<uchar>(i, j) >= v)
				{
					apple.at<uchar>(i, j) = 255;
				}
				else
				{
					apple.at<uchar>(i, j) = 0;
				}
			}
		}
		imshow("Gray", apple);
		if (waitKey(1) == 'e')
		{
			break;
		}

	}
	return 0;
}

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\Ex1.png", 1);
	Mat apple(a.rows, a.cols, CV_8UC3, Scalar(0, 0, 0));

	namedWindow("Gray", WINDOW_AUTOSIZE);
	int b = 255;
	int g = 255;
	int r = 255;

	while (1)
	{
		createTrackbar("Red", "Gray", &r, 255);
		createTrackbar("Green", "Gray", &g, 255);
		createTrackbar("Blue", "Gray", &b, 255);
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				if (a.at<Vec3b>(i, j)[0] <= b && a.at<Vec3b>(i, j)[1] <= g && a.at<Vec3b>(i, j)[2] <= r)
				{
					apple.at<Vec3b>(i, j) = a.at<Vec3b>(i, j);
				}
				else
				{
					apple.at<Vec3b>(i, j)[0] = 0;
					apple.at<Vec3b>(i, j)[1] = 0;
					apple.at<Vec3b>(i, j)[2] = 0;
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

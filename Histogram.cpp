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
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\Test.png", 0);

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
	int max = 0;
	for (int i = 0; i < 256; i++)
	{
		if (intensity[i]>max)
		{
			max = intensity[i];
		}
	}
	printf("%d", max);
	int scale = max / 350;
	Mat b(512, 512, CV_8UC1, Scalar(255));
	Mat c(512, 512, CV_8UC1, Scalar(0));
	for (int i = 0; i < 256; i++)
	{
		for (int k = 0; k < 2; k++)
		{

			for (int j = 0; j <= (intensity[i] / scale); j++)
			{
				b.at<uchar>(j, i) = 0;
			}
		}
	}
	for (int i = 0; i < 512; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			c.at<uchar>(i, j) = b.at<uchar>(512 - i - 1, j);
		}
	}
	imshow("Histogram", c);
	waitKey(0);
	return 0;
}

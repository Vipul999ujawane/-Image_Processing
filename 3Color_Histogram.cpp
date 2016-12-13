/*#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
#include <windows.h>5
using namespace cv;
using namespace std;
int main()
{

	//namedWindow("Double", WINDOW_AUTOSIZE);
	//createTrackbar("Cols", "Double", &cols, 100);
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\8.jpg", 1);

	int red[256];
	int blue[256];
	int green[256];
	for (int i = 0; i < 256; i++)
	{
		red[i] = 0;
		blue[i] = 0;
		green[i] = 0;
	}
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
		{
			red[a.at<Vec3b>(i, j)[2]] += 1;
			green[a.at<Vec3b>(i, j)[1]] += 1;
			blue[a.at<Vec3b>(i, j)[0]] += 1;
		}
	}
	int maxr = 0;
	for (int i = 0; i < 256; i++)
	{
		if (red[i]>maxr)
		{
			maxr = red[i];
		}
	}
	int maxg = 0;
	for (int i = 0; i < 256; i++)
	{
		if (green[i]>maxg)
		{
			maxg = green[i];
		}
	}
	int maxb = 0;
	for (int i = 0; i < 256; i++)
	{
		if (blue[i]>maxb)
		{
			maxb = blue[i];
		}
	}
	int scaler = maxr / 200;
	int scaleb = maxb / 200;
	int scaleg = maxg / 200;
	Mat b(256, 256, CV_8UC3, Scalar(0, 0, 0));
	Mat c(256, 256, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 256; i++)
	{
		for (int k = 0; k < 2; k++)
		{

			for (int j = 0; j <= (red[i] / scaler); j++)
			{
				b.at<Vec3b>(j, i)[2] = 255;
			}
		}
	}
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			c.at<Vec3b>(i, j) = b.at<Vec3b>(256 - i - 1, j);
		}
	}


	Mat d(256, 256, CV_8UC3, Scalar(0, 0, 0));
	Mat e(256, 256, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 256; i++)
	{
		for (int k = 0; k < 2; k++)
		{

			for (int j = 0; j <= (green[i] / scaleg); j++)
			{
				d.at<Vec3b>(j, i)[1] = 255;
			}
		}
	}
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			e.at<Vec3b>(i, j) = d.at<Vec3b>(256 - i - 1, j);
		}
	}


	Mat f(256, 256, CV_8UC3, Scalar(0, 0, 0));
	Mat g(256, 256, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 256; i++)
	{
		for (int k = 0; k < 2; k++)
		{

			for (int j = 0; j <= (blue[i] / scaleb); j++)
			{
				f.at<Vec3b>(j, i)[0] = 255;
			}
		}
	}
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			g.at<Vec3b>(i, j) = f.at<Vec3b>(256 - i - 1, j);
		}
	}
	imshow("Red", c);
	imshow("Green", e);
	imshow("Blue", g);
	waitKey(0);
	return 0;
}*/
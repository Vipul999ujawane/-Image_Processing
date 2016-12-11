#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int opt;
	cout << "Enter 1 for Reflection alonf y-axis\nEnter 2 for refleciton along x-axis" << endl;
	cin >> opt;
	Mat a = imread("Test.jpeg", 1);
	Mat b(a.rows, a.cols, CV_8UC3, Scalar(0, 0, 0));
	Mat c(2 * a.rows, a.cols, CV_8UC3, Scalar(0, 0, 0));
	Mat d(a.rows, 2 * a.cols, CV_8UC3, Scalar(0, 0, 0));
	if (opt == 1)
	{

		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				b.at<Vec3b>(i, j)[0] = a.at<Vec3b>(i, a.cols - j - 1)[0];
				b.at<Vec3b>(i, j)[1] = a.at<Vec3b>(i, a.cols - j - 1)[1];
				b.at<Vec3b>(i, j)[2] = a.at<Vec3b>(i, a.cols - j - 1)[2];
			}
		}
		int k = 0;
		for (int i = 0; i < d.rows; i++)
		{
			for (k = 0; k < a.cols; k++)
			{
				d.at<Vec3b>(i, k)[0] = a.at<Vec3b>(i, k)[0];
				d.at<Vec3b>(i, k)[1] = a.at<Vec3b>(i, k)[1];
				d.at<Vec3b>(i, k)[2] = a.at<Vec3b>(i, k)[2];
			}
			for (; k < d.cols; k++)
			{
				d.at<Vec3b>(i, k)[0] = b.at<Vec3b>(i, k - a.cols)[0];
				d.at<Vec3b>(i, k)[1] = b.at<Vec3b>(i, k - a.cols)[1];
				d.at<Vec3b>(i, k)[2] = b.at<Vec3b>(i, k - a.cols)[2];
			}
		}
		imshow("Mirror Image", d);
	}
	if (opt == 2)
	{

		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				b.at<Vec3b>(i, j)[0] = a.at<Vec3b>(a.rows - i - 1, j)[0];
				b.at<Vec3b>(i, j)[1] = a.at<Vec3b>(a.rows - i - 1, j)[1];
				b.at<Vec3b>(i, j)[2] = a.at<Vec3b>(a.rows - i - 1, j)[2];
			}
		}
		int i = 0;
		for (; i < a.rows; i++)
		{
			for (int k = 0; k < a.cols; k++)
			{
				c.at<Vec3b>(i, k)[0] = a.at<Vec3b>(i, k)[0];
				c.at<Vec3b>(i, k)[1] = a.at<Vec3b>(i, k)[1];
				c.at<Vec3b>(i, k)[2] = a.at<Vec3b>(i, k)[2];
			}
		}
		for (; i < c.rows; i++)
		{
			for (int k = 0; k < a.cols; k++)
			{
				c.at<Vec3b>(i, k)[0] = b.at<Vec3b>(i - a.rows, k)[0];
				c.at<Vec3b>(i, k)[1] = b.at<Vec3b>(i - a.rows, k)[1];
				c.at<Vec3b>(i, k)[2] = b.at<Vec3b>(i - a.rows, k)[2];
			}
		}
		imshow("Mirror Image", c);
	}
	imwrite("Mirror.jpg", b);
	waitKey(0);
	return 0;
}

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int vertical_filter(int array[])
{
	int i = 0;
	float sum = 0;
	float weight[] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
	for (i = 0; i < 9; i++)
	{
		sum += (array[i] * weight[i]);
	}
	return (int)sum;
}
int horizontal_filter(int array[])
{
	int i = 0;
	float sum = 0;
	float weight[] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
	for (i = 0; i < 9; i++)
	{
		sum += (array[i] * weight[i]);
	}
	return (int)sum;
}
int main()
{
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\zebra.jpg", 0);
	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));
	Mat c(a.rows, a.cols, CV_8UC1, Scalar(0));
	for (int i = 1; i < a.rows - 1; i++)
	{
		for (int j = 1; j < a.cols - 1; j++)
		{
			int arr[9];
			int m = 0;
			for (int k = i - 1; k <= i + 1; k++)
			{
				for (int l = j - 1; l <= j + 1; l++)
				{
					arr[m] = a.at<uchar>(k, l);
					m++;
				}
			}
			int vertical = vertical_filter(arr);
			int horizontal = horizontal_filter(arr);
			c.at<uchar>(i, j) = sqrt((vertical*vertical + horizontal*horizontal) / 2);
		}
	}
	int thresh = 130;
	namedWindow("Edges", WINDOW_AUTOSIZE);
	Mat d(a.rows, a.cols, CV_8UC1, Scalar(0));
	while (1)
	{
		createTrackbar("Edge_Fine", "Edges", &thresh, 255);
		//printf("%d\n", thresh);
		for (int i = 0; i < c.rows; i++)
		{
			for (int j = 0; j < c.cols; j++)
			{
				if (c.at<uchar>(i, j)<thresh)
				{
					d.at<uchar>(i, j) = 0;
				}
				else
				{
					d.at<uchar>(i, j) = 255;
				}
			}
		}
		imshow("Edges", d);
		if (waitKey(1) == '3')
		{
			break;
		}
	}
	//imshow("Mean", b);
	//imshow("Median", c);
	//imwrite("lisa.jpg",c);
	//waitKey(0);
	return 0;
}

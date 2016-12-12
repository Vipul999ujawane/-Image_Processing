#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int median(int array[])
{
	sort(array, array + 25);
	return array[13];
}
int mean(int array[])
{
	int i = 0;
	float sum = 0;
	float weight[] = { 0.003765, 0.015019, 0.023792, 0.015019, 0.003765, 0.003765, 0.015019, 0.023792, 0.015019, 0.003765, 0.023792, 0.094907, 0.150342, 0.094907, 0.023792, 0.015019, 0.059912, 0.094907, 0.059912, 0.015019, 0.003765, 0.015019, 0.023792, 0.015019, 0.003765 };
	for (i = 0; i < 25; i++)
	{
		sum += (array[i] * weight[i]);
	}
	return (int)sum;
}
int main()
{
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\lisa.png", 0);
	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));
	Mat c(a.rows, a.cols, CV_8UC1, Scalar(0));
	for (int i = 2; i < a.rows - 2; i++)
	{
		for (int j = 2; j < a.cols - 2; j++)
		{
			int arr[25];
			int m = 0;
			for (int k = i - 2; k <= i + 2; k++)
			{
				for (int l = j - 2; l <= j + 2; l++)
				{
					arr[m] = a.at<uchar>(k, l);
					m++;
				}
			}
			c.at<uchar>(i, j) = median(arr);
			b.at<uchar>(i, j) = mean(arr);
		}
	}
	imshow("Mean", b);
	imshow("Median", c);
	//imwrite("lisa.jpg",c);
	waitKey(0);
	return 0;
}

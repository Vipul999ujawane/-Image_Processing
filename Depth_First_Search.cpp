#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void dfs(Mat a, Mat b, int i, int j, int counter)
{
	b.at<uchar>(i, j) = 20*counter;
	for (int k = i - 1; k <= i + 1; k++)
	{
		for (int l = j - 1; l <= j + 1; l++)
		{
			if (b.at<uchar>(k, l) == 0 && a.at<uchar>(k, l) ==255)
			{
				dfs(a, b, k, l, counter);
			}
		}
	}
}
int main()
{
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\blobs.jpg", 0);
	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));
	int counter = 1;
	for (int i = 1; i < a.rows-1; i++)
	{
		for (int j = 1; j < a.cols-1; j++)
		{
			if (b.at<uchar>(i, j) == 0 && a.at<uchar>(i, j)==255)
			{
				dfs(a, b, i, j, counter);
				counter++;
			}
		}
	}
	imshow("Origin", a);
	imshow("Result", b);
	printf("Blobs=%d\n", counter-1);
	waitKey(0);
}

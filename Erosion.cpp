/*#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void erode(Mat a, Mat clone,Mat clone2, int color, int coloropp)
{
	for (int i = 1; i < a.rows - 1; i++)
	{
		for (int j = 1; j < a.cols - 1; j++)
		{
			int flag = 1;
			if (a.at<uchar>(i, j) == color)
			{
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++)
					{
						if (clone.at<uchar>(k, l) == coloropp)
						{
							flag = 0;
							break;
						}
						if (flag == 0)
						{
							break;
						}
					}
				}
				if (flag == 0)
				{
					clone2.at<uchar>(i, j) = coloropp;
				}
			}
		}
	}
}
/*void dilate()
{
	for (int i = 1; i < a.rows - 1; i++)
	{
		for (int j = 1; j < a.cols - 1; j++)
		{
			if (a.at<uchar>(i, j) == 0)
			{
				int c = 0;
				int arr[9];
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++)
					{
						arr[c++] = clone.at<uchar>(k, l);
					}
				}
				if (isWhite(arr) == 1)
				{
					clone.at<uchar>(i, j) = 255;
				}
			}
		}
	}
}*/
/*
int main()
{
	Mat	a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\filter4.png", 0);
	Mat clone = a.clone();
	erode(a,a,clone,255,0);
	erode(a, clone,clone ,0, 255);
	erode(a, a, clone, 255, 0);
	erode(clone, clone, clone, 0,255);
	//dilate();
	imshow("Erosion-Dilation", a);
	waitKey(0);
	imshow("Erosion-Dilation", clone);
	//imwrite("Eroded.jpg", clone);
	waitKey(0);
	return 0;
}*/
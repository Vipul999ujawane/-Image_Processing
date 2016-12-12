#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a = imread("Ex1.png", 1);
	Mat apple(a.rows, a.cols, CV_8UC1, Scalar(0));
	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j < a.cols; j++)
		{
			if (a.at<Vec3b>(i, j)[2]>a.at<Vec3b>(i, j)[1] + 100 && a.at<Vec3b>(i, j)[2]>a.at<Vec3b>(i, j)[0] + 100)
			{
				apple.at<uchar>(i, j) = 255;
			}
			else{
				apple.at<uchar>(i, j) = 0;
			}
		}
	}
	imshow("Original", a);
	imshow("Gray", apple);
	waitKey(0);
	return 0;

}

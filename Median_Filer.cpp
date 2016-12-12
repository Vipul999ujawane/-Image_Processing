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
int main()
{
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\veg.jpg", 0);
	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));
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
			b.at<uchar>(i, j) = median(arr);
		}
	}
	imshow("Histogram", b);
	//imwrite("lisa.jpg",b);
	waitKey(0);
	return 0;
}

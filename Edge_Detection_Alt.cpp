/*#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int diff(int arr[]){
	;
	sort(arr, arr + 9);

	return arr[8] - arr[0];
}
int main()
{

	//namedWindow("Double", WINDOW_AUTOSIZE);
	//createTrackbar("Cols", "Double", &cols, 100);
	Mat a = imread("D:\\Vipul\\Documents\\Workspace\\OpenCVProject\\OpenCVProject\\Lenna.jpg", 0);
	Mat binary(a.rows, a.cols, CV_8UC1, Scalar(0));
	namedWindow("Edges", WINDOW_AUTOSIZE);
	int tolerance = 0;

	while (1)
	{
		createTrackbar("Edge_Fine", "Edges", &tolerance, 255);
		for (int i = 1; i < a.rows - 1; i++)
		{
			for (int j = 1; j < a.cols - 1; j++)
			{
				int c = 0;
				int arr[9];
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++)
					{
						arr[c] = a.at<uchar>(k, l);
						c++;
					}
				}
				if (diff(arr)>tolerance)
				{
					binary.at<uchar>(i, j) = 255;
				}
				else{
					binary.at<uchar>(i, j) = 0;
				}
			}
		}
		imshow("Edges", binary);
		if (waitKey(1) == '3')
		{
			break;
		}
	}

	//imshow("Trump", a);
	//imshow("Donald", binary);
	waitKey(0);
	return 0;
}*/
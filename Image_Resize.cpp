#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int rows = 1;
	int cols = 1;
	namedWindow("Double", WINDOW_AUTOSIZE);
	createTrackbar("Rows", "Double", &rows, 100);
	createTrackbar("Cols", "Double", &cols, 100);
	Mat a = imread("deadpool.jpg", 1);

	while (1)
	{
		Mat Double(rows*a.rows, cols*a.cols, CV_8UC3, Scalar(0, 0, 0));
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				for (int k = 0; k <rows; k++)
				{
					for (int l = 0; l < cols; l++)
					{
						Double.at<Vec3b>(rows * i + k, cols * j + l) = a.at<Vec3b>(i, j);
					}
				}
			}
		}
		//namedWindow("Gray", WINDOW_AUTOSIZE);
		//imshow("Original", a);
		imshow("Double", Double);
		if (waitKey(1) == 'e')
		{
			break;
		}
		if (rows == 0)
		{
			rows = 1;
		}
		if (cols == 0)
		{
			cols = 1;
		}
	}

	return 0;
}
